#include "Compiler.h"
#include <iostream>

//SETUP

Compiler::Compiler() {
// Nothing special needed to initialize yet
}
// main.cpp handles the root node of the AST usually the BLOCKSTMT to the  compile function

Chunk Compiler::compile(ASTNode* ast) {
    
    currentChunk = Chunk();  //creates an empty chunk using the constructor
    
                             //   AST Tree for code: let x = 5; print x;

                             //          BlockStmt
                             //         /         \
                             //     VarDecl     PrintStmt
                             //     (x = 5)     (print x)
                             //         |            |
                             //     LiteralExpr  VariableExpr
                             //     (value: 5)   (name: x)

                             // The compiler visits each node → generates bytecode for each
    
    if (ast) {   //does the AST exists
        ast->accept(*this);    //if yes then start walking thru it and generate bytecode 
    }
    
    //  Always add a 'RETURN' instruction at the very end so the VM knows to stop
    emitByte(static_cast<uint8_t>(Opcode::OP_RETURN));
    
    
    return currentChunk;
}


// HELPER METHODS 

void Compiler::emitByte(uint8_t byte) {
    currentChunk.writeByte(byte); // Add a single instruction to the list
}

void Compiler::emitBytes(uint8_t byte1, uint8_t byte2) {
    emitByte(byte1);
    emitByte(byte2);
}

void Compiler::emitConstant(Value value) {
   
    emitByte(static_cast<uint8_t>(Opcode::OP_CONSTANT));  //write OP_CONSTANT
                                                          //Afterwards  add index and store the value in the vault
   
    int index = currentChunk.addConstant(value);
    emitByte(static_cast<uint8_t>(index));
}


// EXPRESSIONS (Math & Values)

void Compiler::visit(LiteralExpr* expr) {
    
    int number = std::stoi(expr->value.lexeme);   //convert the string to number
    
    Value val;
    val.type = ValueType::VAL_INT;
    val.as = number;
    
    emitConstant(val);    // add OP_constant , then add value to the vault , then add index to the byte code
}

void Compiler::visit(BinaryExpr* expr) {
    // Math is evaluated Left-to-Right!
    
    // 1. Compile the left side (e.g., the '5' in 5 + 3)
    expr->left->accept(*this);
    
    // 2. Compile the right side (e.g., the '3' in 5 + 3)
    expr->right->accept(*this);
    
    // 3. Emit the instruction to add/subtract/etc. them together
    switch (expr->op.type) {
        case TokenType::PLUS:          emitByte(static_cast<uint8_t>(Opcode::OP_ADD)); break;
        case TokenType::MINUS:         emitByte(static_cast<uint8_t>(Opcode::OP_SUB)); break;
        case TokenType::STAR:          emitByte(static_cast<uint8_t>(Opcode::OP_MUL)); break;
        case TokenType::SLASH:         emitByte(static_cast<uint8_t>(Opcode::OP_DIV)); break;
        case TokenType::EQUAL_EQUAL:   emitByte(static_cast<uint8_t>(Opcode::OP_EQUAL)); break;
        case TokenType::LESS:          emitByte(static_cast<uint8_t>(Opcode::OP_LESS)); break;
        default: break; // Should not happen
    }
}

void Compiler::visit(VariableExpr* expr) {
    // When we want to READ a variable (like 'print x;'):
    // 1. Save the variable name ("x") into the vault
    Value nameVal;
    nameVal.type = ValueType::VAL_STRING;
    nameVal.as = expr->name.lexeme;
    
    int index = currentChunk.addConstant(nameVal);
    
    // 2. Tell the VM to go get it!
    emitBytes(static_cast<uint8_t>(Opcode::OP_GET_GLOBAL), static_cast<uint8_t>(index));
}


//  STATEMENTS (Actions) 

void Compiler::visit(PrintStmt* stmt) {
    // 1. Compile the math/value we want to print
    stmt->expression->accept(*this);
    
    // 2. Tell the VM to print whatever is sitting on top of the stack
    emitByte(static_cast<uint8_t>(Opcode::OP_PRINT));
}

void Compiler::visit(VarDecl* stmt) {
    // When we CREATE a new variable (like 'let x = 10;'):
    
    // 1. Compile the value (the '10')
    if (stmt->initializer) {
        stmt->initializer->accept(*this);
    } else {
        // If no value, default to false/0 (simplified for now)
        emitByte(static_cast<uint8_t>(Opcode::OP_FALSE));
    }
    
    // 2. Save the name ("x") into the constant vault
    Value nameVal;
    nameVal.type = ValueType::VAL_STRING;
    nameVal.as = stmt->name.lexeme;
    
    int index = currentChunk.addConstant(nameVal);
    
    // 3. Tell the VM to create the global variable!
    emitBytes(static_cast<uint8_t>(Opcode::OP_DEFINE_GLOBAL), static_cast<uint8_t>(index));
}

void Compiler::visit(BlockStmt* stmt) {
    // A block { } is just a list of statements. Go through them one by one!
    for (auto& s : stmt->statements) {
        s->accept(*this);
    }
}

void Compiler::visit(IfStmt* stmt) {
    // IF statements are complex. We have to "JUMP" over the code if the test is false.
    // (We will implement exact Jump distances later when the VM is built!)
    
    // 1. Compile the test (e.g. x < 10)
    stmt->condition->accept(*this);
    
    // 2. (Placeholder) Jump if false
    emitByte(static_cast<uint8_t>(Opcode::OP_JUMP_IF_FALSE));
    emitByte(0); // Dummy distance
    
    // 3. The code to run if TRUE
    stmt->thenBranch->accept(*this);
}

void Compiler::visit(WhileStmt* stmt) {
    // WHILE loops jump backwards!
    // (We will implement exact Jump distances later when the VM is built!)
    
    stmt->condition->accept(*this);
    
    // Jump over the body if the loop is finished
    emitByte(static_cast<uint8_t>(Opcode::OP_JUMP_IF_FALSE));
    emitByte(0); // Dummy distance
    
    stmt->body->accept(*this);
    
    // Jump back to the start!
    emitByte(static_cast<uint8_t>(Opcode::OP_LOOP));
    emitByte(0); // Dummy distance
}

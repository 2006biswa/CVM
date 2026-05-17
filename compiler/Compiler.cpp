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




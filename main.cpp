// Entry point for CVM++
// This file should handle the overall execution flow.

#include <iostream>
#include <string>
#include <iomanip> // For pretty printing

// Include all the core modules of the CVM++ pipeline
#include "lexer/Lexer.h"
#include "parser/Parser.h"
#include "parser/ASTPrinter.h"
#include "compiler/Compiler.h"
#include "vm/VM.h"

//Helper to beautifully print the bytecode
void disassembleChunk(const Chunk& chunk) {
    std::cout << "--- BYTECODE CHUNK ---" << std::endl;
    for (size_t i = 0; i < chunk.code.size(); i++) {
        std::cout << std::setw(4) << std::setfill('0') << i << "  ";
        uint8_t instruction = chunk.code[i];
        
        switch (static_cast<Opcode>(instruction)) {
            case Opcode::OP_CONSTANT: {
                uint8_t constantIndex = chunk.code[++i]; // The next byte is the index!
                std::cout << "OP_CONSTANT      " << (int)constantIndex << " (Value: ";
                const Value& val = chunk.constants[constantIndex];
                if (val.isInt()) std::cout << std::get<int>(val.as);
                else if (val.isBool()) std::cout << (std::get<bool>(val.as) ? "true" : "false");
                else if (val.isString()) std::cout << "'" << std::get<std::string>(val.as) << "'";
                std::cout << ")" << std::endl;
                break;
            }
            case Opcode::OP_ADD: std::cout << "OP_ADD" << std::endl; break;
            case Opcode::OP_SUB: std::cout << "OP_SUB" << std::endl; break;
            case Opcode::OP_MUL: std::cout << "OP_MUL" << std::endl; break;
            case Opcode::OP_DIV: std::cout << "OP_DIV" << std::endl; break;
            case Opcode::OP_PRINT: std::cout << "OP_PRINT" << std::endl; break;
            case Opcode::OP_DEFINE_GLOBAL: {
                uint8_t index = chunk.code[++i];
                std::cout << "OP_DEFINE_GLOBAL " << (int)index << " (Name: '" << std::get<std::string>(chunk.constants[index].as) << "')" << std::endl;
                break;
            }
            case Opcode::OP_GET_GLOBAL: {
                uint8_t index = chunk.code[++i];
                std::cout << "OP_GET_GLOBAL    " << (int)index << " (Name: '" << std::get<std::string>(chunk.constants[index].as) << "')" << std::endl;
                break;
            }
            case Opcode::OP_RETURN: std::cout << "OP_RETURN" << std::endl; break;
            default: std::cout << "Unknown Opcode: " << (int)instruction << std::endl; break;
        }
    }
    std::cout << "----------------------" << std::endl;
}

// We added this helper to test our new ASTPrinter AND Compiler!
void runCode(const std::string& sourceCode) {
    std::cout << "\n--- Source Code ---" << std::endl;
    std::cout << sourceCode << "-------------------\n" << std::endl;

    // 1. The Lexer chops the string into Tokens
    Lexer lexer(sourceCode);
    auto tokens = lexer.tokenize();

    // 2. The Parser builds the 2D Tree
    Parser parser(tokens);
    auto ast = parser.parse();

    if (ast) {
        // 3. Print the Tree so we can visually check it
        std::cout << "--- AST Tree ---" << std::endl;
        ASTPrinter printer;
        printer.print(ast.get());
        std::cout << "----------------\n" << std::endl;

        // 4. Compile the Tree into flat Bytecode!
        Compiler compiler;
        Chunk chunk = compiler.compile(ast.get());

        // 5. Disassemble the chunk to visually prove the bytecode is correct!
        disassembleChunk(chunk);

        // 6. Execute the Bytecode using our Virtual Machine!
        std::cout << "\n--- VM Output ---" << std::endl;
        VM vm;
        vm.interpret(&chunk);
        std::cout << "-----------------" << std::endl;
    } else {
        std::cout << "Compilation Failed due to Syntax Error." << std::endl;
    }
}

int main(int argc, char* argv[]) {
    
    // TODO 1: Parse command-line arguments.
    // If argc == 1, start the interactive REPL (Read-Eval-Print Loop).
    // If argc == 2, read the file specified by argv[1] and run it.
    // Otherwise, print usage instructions and exit.
   
    // TODO 2: In REPL mode:
    // - Loop infinitely:
    //   - Print a prompt (e.g., "> ").
    //   - Read a line of input using std::getline.
    //   - Pass the input to the Lexer, then Parser, Compiler, and VM.
   
    // TODO 3: In File Runner mode:
    // - Open the file and read its entire contents into a std::string.
    // - Pass the string to the compilation pipeline.
    
    // General Pipeline Example (Do not write the code yet, just structure):
    // 1. Lexer lexer(sourceCode);
    // 2. auto tokens = lexer.tokenize();
    // 3. Parser parser(tokens);
    // 4. auto ast = parser.parse();
    // 5. Compiler compiler;
    // 6. auto bytecode = compiler.compile(ast.get());
    // 7. VM vm;
    // 8. vm.interpret(bytecode);


    std::cout << "Welcome to CVM++! Structure initialized." << std::endl;

    //  QUICK TEST FOR THE COMPILER
    // Let's test math, variables, and printing all at once!
    std::string testCode = 
        "let x = 5 + 5 * 2;\n"
        "let y = x + 10;\n"
        "print y;\n";

    runCode(testCode);

    return 0;
}

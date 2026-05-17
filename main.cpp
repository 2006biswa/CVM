// Entry point for CVM++
// This file should handle the overall execution flow.

#include <iostream>
#include <string>

// Include all the core modules of the CVM++ pipeline
#include "lexer/Lexer.h"
#include "parser/Parser.h"
#include "parser/ASTPrinter.h"
#include "compiler/Compiler.h"
#include "vm/VM.h"

// We added this helper to test our new ASTPrinter!
void runCode(const std::string& sourceCode) {
    std::cout << "\n--- Compiling Code ---" << std::endl;
    std::cout << sourceCode << "----------------------\n" << std::endl;

    // 1. The Lexer chops the string into Tokens
    Lexer lexer(sourceCode);
    auto tokens = lexer.tokenize();

    // 2. The Parser builds the 2D Tree
    Parser parser(tokens);
    auto ast = parser.parse();

    // 3. If parsing was successful, print the Tree!
    if (ast) {
        std::cout << "--- AST Tree ---" << std::endl;
        ASTPrinter printer;
        printer.print(ast.get());
        std::cout << "----------------" << std::endl;
    } else {
        std::cout << "Compilation Failed due to Syntax Error." << std::endl;
    }
}

int main(int argc, char* argv[]) {
    // ---------------------------------------------------------
    // TODO 1: Parse command-line arguments.
    // If argc == 1, start the interactive REPL (Read-Eval-Print Loop).
    // If argc == 2, read the file specified by argv[1] and run it.
    // Otherwise, print usage instructions and exit.
    // ---------------------------------------------------------

    // ---------------------------------------------------------
    // TODO 2: In REPL mode:
    // - Loop infinitely:
    //   - Print a prompt (e.g., "> ").
    //   - Read a line of input using std::getline.
    //   - Pass the input to the Lexer, then Parser, Compiler, and VM.
    // ---------------------------------------------------------

    // ---------------------------------------------------------
    // TODO 3: In File Runner mode:
    // - Open the file and read its entire contents into a std::string.
    // - Pass the string to the compilation pipeline.
    // ---------------------------------------------------------

    // ---------------------------------------------------------
    // General Pipeline Example (Do not write the code yet, just structure):
    // 1. Lexer lexer(sourceCode);
    // 2. auto tokens = lexer.tokenize();
    // 3. Parser parser(tokens);
    // 4. auto ast = parser.parse();
    // 5. Compiler compiler;
    // 6. auto bytecode = compiler.compile(ast.get());
    // 7. VM vm;
    // 8. vm.interpret(bytecode);
    // ---------------------------------------------------------

    std::cout << "Welcome to CVM++! Structure initialized." << std::endl;

    // A quick hardcoded test to prove our Parser works!
    std::string testCode = 
        "let x = 5 + 5 * 2;\n"
        "let y = x + 10;\n"
        "print y;\n"
        "if (x < y) {\n"
        "    print x;\n"
        "}\n";

    runCode(testCode);

    return 0;
}

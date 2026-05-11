// Entry point for CVM++
// This file should handle the overall execution flow.

#include <iostream>
#include <string>

// Include all the core modules of the CVM++ pipeline
#include "lexer/Lexer.h"
#include "parser/Parser.h"
#include "compiler/Compiler.h"
#include "vm/VM.h"

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
    return 0;
}

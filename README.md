# CVM++

A Stack-Based Virtual Machine and Custom Scripting Language Compiler built in C++.

## Project Structure

- `src/lexer`: Converts raw source code strings into Tokens.
- `src/parser`: Arranges Tokens into an Abstract Syntax Tree (AST) using Recursive Descent.
- `src/compiler`: Flattens the AST into an array of raw Bytecode instructions (Opcodes).
- `src/vm`: Executes the Bytecode using a fast, stack-based execution loop.
- `scripts`: Sample scripts for the CVM++ language.

## Build Instructions
1. `mkdir build && cd build`
2. `cmake ..`
3. `make`
4. `./cvm`

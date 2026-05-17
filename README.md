# CVM++

A Stack-Based Virtual Machine and Custom Scripting Language Compiler built in C++.

## Project Structure

- `src/lexer`: Converts raw source code strings into Tokens.
- `src/parser`: Arranges Tokens into an Abstract Syntax Tree (AST) using Recursive Descent.
- `src/compiler`: Flattens the AST into an array of raw Bytecode instructions (Opcodes).
- `src/vm`: Executes the Bytecode using a fast, stack-based execution loop.
- `scripts`: Sample scripts for the CVM++ language.

## Build Instructions (Windows/PowerShell)
1. Open your terminal in the project directory (`CVM/`).
2. Create and enter the build directory: `mkdir build; cd build`
3. Configure the project: `cmake ..`
4. Compile the code: `cmake --build .`
5. Run the executable: `.\cvm.exe`

## Testing the Parser (AST Printer)
Currently, `main.cpp` is hardcoded to run a visual test of the **Lexer** and **Parser**. 
When you run the executable (`.\cvm.exe`), it will parse a hardcoded code snippet and print out a Lisp-style 2D Abstract Syntax Tree (AST) to your terminal. 

Example output:
```lisp
(block
  (let x = (+ 5 (* 5 2)))
  (print x)
)
```
This visually proves that the Recursive Descent Parser is working perfectly!

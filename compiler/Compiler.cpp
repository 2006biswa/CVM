#include "Compiler.h"

Compiler::Compiler() {
    // ---------------------------------------------------------
    // TODO: Initialize compiler state.
    // ---------------------------------------------------------
}

std::vector<uint8_t> Compiler::compile(ASTNode* ast) {
    std::vector<uint8_t> bytecode;
    // ---------------------------------------------------------
    // TODO: Start traversing the AST from the root node.
    // For each node, emit the corresponding opcodes.
    // ---------------------------------------------------------
    
    // Example for a Binary Expression (e.g., 2 + 3):
    // 1. Compile the left child (emits OP_CONSTANT 2).
    // 2. Compile the right child (emits OP_CONSTANT 3).
    // 3. Emit the operator opcode (OP_ADD).
    
    // Example for 'print x':
    // 1. Compile the expression 'x' (emits OP_GET_VAR or OP_CONSTANT).
    // 2. Emit OP_PRINT.

    return bytecode;
}

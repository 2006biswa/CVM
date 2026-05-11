#include "VM.h"
#include "Opcode.h"
#include <iostream>

VM::VM() {
    // ---------------------------------------------------------
    // TODO: Initialize the instruction pointer and clear the stack.
    // ---------------------------------------------------------
}

void VM::interpret(const std::vector<uint8_t>& bytecode) {
    // ---------------------------------------------------------
    // TODO: Implement the main fetch-decode-execute loop.
    // ---------------------------------------------------------
    
    // size_t ip = 0;
    // while (ip < bytecode.size()) {
    //     uint8_t instruction = bytecode[ip++];
    //     
    //     switch (static_cast<Opcode>(instruction)) {
    //         case Opcode::OP_ADD: {
    //             // int b = pop();
    //             // int a = pop();
    //             // push(a + b);
    //             break;
    //         }
    //         case Opcode::OP_PRINT: {
    //             // std::cout << pop() << std::endl;
    //             break;
    //         }
    //         // ... implement other opcodes ...
    //         case Opcode::OP_HALT: {
    //             return;
    //         }
    //     }
    // }
}

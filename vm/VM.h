#ifndef VM_H
#define VM_H

#include <vector>
#include <cstdint>
#include <unordered_map>
#include <string>
#include "../common/Value.h" // Using the new high-level Value structure

class VM {
public:
    VM();
    void interpret(const std::vector<uint8_t>& bytecode);

private:
    // ---------------------------------------------------------
    // TODO 1: Professional VM State
    // - Instruction Pointer (ip): size_t tracking the current index.
    // - The Stack: std::vector<Value> (Now supports mixed types!)
    // - Global Variables: std::unordered_map<std::string, Value>
    // ---------------------------------------------------------
    
    // ---------------------------------------------------------
    // TODO 2: High-Performance Stack Operations
    // - void push(Value value)
    // - Value pop()
    // - Value peek(int distance = 0) // Look at the stack without popping
    // ---------------------------------------------------------
};

#endif // VM_H

#include "VM.h"
#include "Opcode.h"
#include <iostream>

VM::VM() {
    // When the VM boots up, here we implemented the constructor
    ip = 0;
    currentChunk = nullptr;
}

// HIGH-PERFORMANCE STACK OPERATIONS

void VM::push(Value value) {
    stack.push_back(value);
}

Value VM::pop() {
   Value top = stack.back();
    stack.pop_back();
    return top;
}

Value VM::peek(int distance) {
    // Distance 0 means the very top of the stack.
    // Distance 1 means the item just below the top.
    return stack[stack.size() - 1 - distance];
}

// THE EXECUTION ENGINE 

void VM::interpret(Chunk* chunk) {
    //  Load the chunk into the VM's brain
    currentChunk = chunk;
    ip = 0; // Start at the very first instruction

    // The Infinite Execution Loop (Fetch -> Decode -> Execute)   //SIMILAR TO HARDWARE BEHAVIOUR SAME AS THAT OF CPU
    while (true) {
        // FETCH: Get the CURRENT instruction and move the pointer forward
        uint8_t instruction = currentChunk->code[ip++];
        
        // DECODE & EXECUTE: What does this instruction mean?

        // AS IT IS BEING TOLD THAT OUR VIRTUAL MACHINE IS GOING TO BE A LARGE SWITCH STATEMENT
        
        switch (static_cast<Opcode>(instruction)) {
            
            case Opcode::OP_CONSTANT: {
                // Read the next byte (which is the index to the vault)
                uint8_t constantIndex = currentChunk->code[ip++];
                // Get the value from the vault
                Value constantValue = currentChunk->constants[constantIndex];
                // Push it onto the stack!
                push(constantValue);
                break;
            }
            
            case Opcode::OP_TRUE: {
                Value val;
                val.type = ValueType::VAL_BOOL;
                val.as = true;
                push(val);
                break;
            }

            case Opcode::OP_FALSE: {
                Value val;
                val.type = ValueType::VAL_BOOL;
                val.as = false;
                push(val);
                break;
            }
            
            case Opcode::OP_ADD: {
                // Pop the top two values
                Value b = pop();
                Value a = pop();
                
                // Do the math! (Assuming they are integers for now to keep it simple)
                if (a.isInt() && b.isInt()) {
                    Value result;
                    result.type = ValueType::VAL_INT;
                    result.as = std::get<int>(a.as) + std::get<int>(b.as);
                    push(result);
                }
                break;
            }
            
            case Opcode::OP_SUB: {
                Value b = pop(); Value a = pop();
                if (a.isInt() && b.isInt()) {
                    Value result; result.type = ValueType::VAL_INT; result.as = std::get<int>(a.as) - std::get<int>(b.as);
                    push(result);
                }
                break;
            }
            
            case Opcode::OP_MUL: {
                Value b = pop(); Value a = pop();
                if (a.isInt() && b.isInt()) {
                    Value result; result.type = ValueType::VAL_INT; result.as = std::get<int>(a.as) * std::get<int>(b.as);
                    push(result);
                }
                break;
            }
            
            case Opcode::OP_DIV: {
                Value b = pop(); Value a = pop();
                if (a.isInt() && b.isInt()) {
                    Value result; result.type = ValueType::VAL_INT; result.as = std::get<int>(a.as) / std::get<int>(b.as);
                    push(result);
                }
                break;
            }

            case Opcode::OP_EQUAL: {
                Value b = pop(); Value a = pop();
                if (a.isInt() && b.isInt()) {
                    Value result; result.type = ValueType::VAL_BOOL; result.as = (std::get<int>(a.as) == std::get<int>(b.as));
                    push(result);
                }
                break;
            }

            case Opcode::OP_LESS: {
                Value b = pop(); Value a = pop();
                if (a.isInt() && b.isInt()) {
                    Value result; result.type = ValueType::VAL_BOOL; result.as = (std::get<int>(a.as) < std::get<int>(b.as));
                    push(result);
                }
                break;
            }
            
            case Opcode::OP_PRINT: {
                // Pop whatever is on top of the stack and print it to the screen!
                Value value = pop();
                if (value.isInt()) std::cout << std::get<int>(value.as) << std::endl;
                else if (value.isBool()) std::cout << (std::get<bool>(value.as) ? "true" : "false") << std::endl;
                else if (value.isString()) std::cout << std::get<std::string>(value.as) << std::endl;
                break;
            }
            
            case Opcode::OP_DEFINE_GLOBAL: {
                // Get the name of the variable from the Vault
                uint8_t nameIndex = currentChunk->code[ip++];
                std::string variableName = std::get<std::string>(currentChunk->constants[nameIndex].as);
                
                // Pop the value off the stack, and permanently save it in our Globals Memory!
                globals[variableName] = pop();
                break;
            }
            
            case Opcode::OP_GET_GLOBAL: {
                // Get the name of the variable from the Vault
                uint8_t nameIndex = currentChunk->code[ip++];
                std::string variableName = std::get<std::string>(currentChunk->constants[nameIndex].as);
                
                // Find it in memory, and push its value onto the stack!
                push(globals[variableName]);
                break;
            }
            
            case Opcode::OP_RETURN: {
                // The program is finished! Exit the infinite loop.
                return;
            }
            
            default:
                std::cout << "VM Error: Unknown Instruction!" << std::endl;
                return;
        }
    }
}

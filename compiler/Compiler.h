#ifndef COMPILER_H
#define COMPILER_H

#include <vector>
#include <cstdint>
#include "../parser/AST.h"

// ---------------------------------------------------------
// TODO 1: High-Level Compiler Architecture
// Make the Compiler inherit from ASTVisitor.
// When it visits an AST node (e.g., visit(BinaryExpr*)), 
// it emits the corresponding Bytecode into its array.
// ---------------------------------------------------------
class Compiler : public ASTVisitor {
public:
    Compiler();
    std::vector<uint8_t> compile(ASTNode* ast);
 
    // Visitor implementation methods (TODO: uncomment and override these)
    // void visit(BinaryExpr* expr) override;
    // void visit(LiteralExpr* expr) override;
    // void visit(PrintStmt* stmt) override;

private:
    std::vector<uint8_t> bytecode;
    
    // ---------------------------------------------------------
    // TODO 2: Debugging Features (For Deliverables)
    // As per your goals, you need to optionally "Show the compiled Bytecode".
    // Consider adding a method like `disassembleChunk()`
    // to print the opcodes in a human-readable format.
    // ---------------------------------------------------------

    // Helper methods to write raw bytes
    void emitByte(uint8_t byte);
    void emitBytes(uint8_t byte1, uint8_t byte2);
};

#endif // COMPILER_H

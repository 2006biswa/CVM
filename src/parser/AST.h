#ifndef AST_H
#define AST_H

#include <memory>
#include <vector>
#include "../lexer/Token.h"

// ---------------------------------------------------------
// TODO 1: The Visitor Pattern (High-Level Architecture)
// To keep your compiler professional and modular, use the Visitor Pattern.
// This allows you to separate the AST node definitions from the logic
// that operates on them (like printing the tree, or compiling it).
// ---------------------------------------------------------
class ASTVisitor;

class ASTNode {
public:
    virtual ~ASTNode() = default;
    
    // Every node must accept a visitor
    virtual void accept(ASTVisitor& visitor) = 0;
};

// ---------------------------------------------------------
// TODO 2: Define specific AST Node classes inheriting from ASTNode.
//
// Expression Nodes: BinaryExpr, LiteralExpr, VariableExpr
// Statement Nodes: PrintStmt, VarDecl, BlockStmt, IfStmt, WhileStmt
// ---------------------------------------------------------

// Example structure for the Visitor Interface:
class ASTVisitor {
public:
    // virtual void visit(BinaryExpr* expr) = 0;
    // virtual void visit(LiteralExpr* expr) = 0;
    // virtual void visit(PrintStmt* stmt) = 0;
    virtual ~ASTVisitor() = default;
};

#endif // AST_H

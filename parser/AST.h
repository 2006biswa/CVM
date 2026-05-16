#ifndef AST_H
#define AST_H

#include <memory>
#include <vector>
#include "../lexer/Token.h"

// Forward declarations so classes know about each other
class ASTVisitor;
class BinaryExpr;
class LiteralExpr;
class VariableExpr;
class PrintStmt;
class VarDecl;
class BlockStmt;
class IfStmt;
class WhileStmt;

// IMPLEMENTING THE VISITOR PATTERN(A professional  way of designing compilers)(good designing)
//let's say u have a number of nodes inorder to do a thing suppose print tree or compile or find error u would have to edit each of the node this creates a mess
// rather u make all the nodes dumb that is no logic only data and then create a visitor class for the required purpose

class ASTNode {
public:
    virtual ~ASTNode() = default;  //virtual destructor in order to prevent memory leaks
    
    // Every node must accept a visitor
    virtual void accept(ASTVisitor& visitor) = 0;
};


// Define specific AST Node classes inheriting from ASTNode.


// --- EXPRESSION NODES (Things that produce a value, like 5 + 5) ---

class BinaryExpr : public ASTNode {
public:
    std::unique_ptr<ASTNode> left;  // The left side of the math equation (e.g., the '1' in 1 + 2)
    Token op;                       // The math operator (e.g., the '+' in 1 + 2)
    std::unique_ptr<ASTNode> right; // The right side of the math equation (e.g., the '2' in 1 + 2)

    BinaryExpr(std::unique_ptr<ASTNode> left, Token op, std::unique_ptr<ASTNode> right)
        : left(std::move(left)), op(op), right(std::move(right)) {}           //constructor and using move because single owner

    void accept(ASTVisitor& visitor) override; // Allows the visitor to enter this node
};


#endif // AST_H

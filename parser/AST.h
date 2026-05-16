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




#endif // AST_H

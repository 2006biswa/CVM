#include "Parser.h"

Parser::Parser(const std::vector<Token>& tokens) : tokens(tokens) {
    // ---------------------------------------------------------
    // TODO: Initialize 'current' index to 0.
    // ---------------------------------------------------------
}

std::unique_ptr<ASTNode> Parser::parse() {
    // ---------------------------------------------------------
    // TODO: Implement the top-level parse loop.
    // This usually involves looping while !isAtEnd() and parsing
    // 'declaration()' repeatedly, gathering them into a top-level Program node.
    // ---------------------------------------------------------
    return nullptr;
}

// ---------------------------------------------------------
// TODO: Implement the recursive descent methods here.
// Example logic for 'term()':
// 1. Parse a 'factor()'.
// 2. While match(PLUS) or match(MINUS):
//    a. Store the operator.
//    b. Parse the right-hand 'factor()'.
//    c. Combine left and right into a new BinaryExpr node.
// ---------------------------------------------------------

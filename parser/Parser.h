#ifndef PARSER_H
#define PARSER_H

#include <vector>
#include <memory>
#include <string>
#include <initializer_list>
#include "../lexer/Token.h"
#include "AST.h"

class Parser {
public:
    Parser(const std::vector<Token>& tokens);
    
    
    std::unique_ptr<ASTNode> parse();  // kind of the single button to start the entire  parsing process like turning the tokens into 2-D AST tree

private:
    std::vector<Token> tokens;
    
    
    //  Add internal state tracking:
    
    
    int current = 0; // The 'finger' pointing at the current token we are looking at that is to be parsed
    
   // following recursive descent
    // TODO 2: Declare grammar rule methods (Recursive Descent).
    // These methods correspond to your language grammar:
   
    std::vector<std::unique_ptr<ASTNode>> program();
    std::unique_ptr<ASTNode> declaration();
    std::unique_ptr<ASTNode> statement();
    
    std::unique_ptr<ASTNode> expression();
    std::unique_ptr<ASTNode> equality();
    std::unique_ptr<ASTNode> comparison();
    std::unique_ptr<ASTNode> term();
    std::unique_ptr<ASTNode> factor();
    std::unique_ptr<ASTNode> primary();

    
};

#endif // PARSER_H

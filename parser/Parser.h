#ifndef PARSER_H
#define PARSER_H

#include <vector>
#include <memory>
#include "../lexer/Token.h"
#include "AST.h"

class Parser {
public:
    Parser(const std::vector<Token>& tokens);
    std::unique_ptr<ASTNode> parse();

private:
    std::vector<Token> tokens;
    
    // ---------------------------------------------------------
    // TODO 1: Add internal state tracking:
    // - 'current': integer index pointing to the next token to be parsed.
    // ---------------------------------------------------------
    
    // ---------------------------------------------------------
    // TODO 2: Declare grammar rule methods (Recursive Descent).
    // These methods correspond to your language grammar:
    // - program()      -> entry point, returns a list of statements.
    // - declaration()  -> parses variable declarations (let) or statements.
    // - statement()    -> parses print, if, while, or blocks.
    // - expression()   -> parses general expressions (delegates to equality).
    // - equality()     -> parses '=='
    // - comparison()   -> parses '<'
    // - term()         -> parses '+' and '-'
    // - factor()       -> parses '*' and '/'
    // - primary()      -> parses numbers, booleans, identifiers, and grouping ().
    // ---------------------------------------------------------

    // ---------------------------------------------------------
    // TODO 3: Declare helper methods:
    // - match(TokenType... types): checks if current token matches any in the list, advances if true.
    // - check(TokenType type): checks current token type without advancing.
    // - advance(): consumes and returns the current token.
    // - isAtEnd(): checks if we've reached END_OF_FILE.
    // - consume(TokenType type, string message): expects a specific token or throws a parse error.
    // ---------------------------------------------------------
};

#endif // PARSER_H

#ifndef LEXER_H
#define LEXER_H

#include <string>
#include <vector>
#include "Token.h"

class Lexer {
public:
    Lexer(const std::string& source);
    std::vector<Token> tokenize();

private:
    std::string source;
    
    // ---------------------------------------------------------
    // TODO 1: Add internal state tracking variables:
    // - 'start': points to the first character in the lexeme being scanned.
    // - 'current': points to the character currently being considered.
    // - 'line': tracks the current line number for error reporting.
    // ---------------------------------------------------------

    // ---------------------------------------------------------
    // TODO 2: Declare helper methods for character scanning:
    // - bool isAtEnd(): checks if 'current' >= source.length().
    // - char advance(): consumes the next character and returns it.
    // - bool match(char expected): conditionally consumes a character.
    // - char peek(): looks at the current character without consuming it.
    // - void addToken(TokenType type): creates a token and adds it to the list.
    // ---------------------------------------------------------
};

#endif // LEXER_H

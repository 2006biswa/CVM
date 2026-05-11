#include "Lexer.h"

Lexer::Lexer(const std::string& source) : source(source) {
    // ---------------------------------------------------------
    // TODO: Initialize internal state pointers (start, current, line).
    // ---------------------------------------------------------
}

std::vector<Token> Lexer::tokenize() {
    std::vector<Token> tokens;
    
    // ---------------------------------------------------------
    // TODO: Implement the main tokenization loop.
    // while (!isAtEnd()) {
    //     start = current;
    //     scanToken(); // A function to switch on the current character
    // }
    // tokens.push_back(Token{TokenType::END_OF_FILE, "", line});
    // ---------------------------------------------------------

    // Inside scanToken() (which you need to implement), you should:
    // 1. Switch on the current character.
    // 2. Handle single-character operators (+, -, *, /).
    // 3. Handle multi-character operators (==, <=).
    // 4. Ignore whitespace and comments.
    // 5. Handle string/number literals by delegating to helper functions (e.g., number(), identifier()).
    // 6. Check if an identifier is actually a keyword (let, print, if, etc.).

    return tokens;
}

#ifndef TOKEN_H
#define TOKEN_H

#include <string>

// ---------------------------------------------------------
// TODO 1: Define an enumeration for all Token types.
// Based on the project scope, you will need:
// - Single-character tokens: PLUS, MINUS, STAR, SLASH, EQUAL, LESS, etc.
// - Two-character tokens: EQUAL_EQUAL.
// - Literals: IDENTIFIER, NUMBER (Integers), BOOLEAN (true/false).
// - Keywords: LET, PRINT, IF, ELSE, WHILE, INPUT.
// - Special: END_OF_FILE.
// ---------------------------------------------------------
enum class TokenType {
    // Add token types here
    END_OF_FILE
};

// ---------------------------------------------------------
// TODO 2: Define the Token structure.
// A Token should store:
// - The TokenType.
// - The literal string value (lexeme) exactly as it appeared in code.
// - The line number where it was found (useful for error reporting).
// ---------------------------------------------------------
struct Token {
    TokenType type;
    std::string lexeme;
    int line;
};

#endif // TOKEN_H

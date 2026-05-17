#include "Parser.h"
#include <stdexcept>
#include <iostream>


// CONSTRUCTOR

Parser::Parser(const std::vector<Token>& tokens) : tokens(tokens) {
    current = 0; // When main.cpp creates the Parser, it hands over the tokens vector. We set our current finger to 0 so 
                // we are pointing at the very first token on the conveyor belt.
}


//  HELPER METHODS (Tools to interact with the conveyor belt inorder to build the tree)


Token Parser::peek() {
    if (current >= tokens.size()) {
       
        return Token{TokenType::END_OF_FILE, "", -1}; //returned an object without saving it in a variable
    }
    return tokens[current];
}

Token Parser::previous() {
    return tokens[current - 1];
}

bool Parser::isAtEnd() {
    return peek().type == TokenType::END_OF_FILE; // If the token we are looking at is EOF, we are done!
}

bool Parser::check(TokenType type) {
    if (isAtEnd()) return false;
    return peek().type == type;  // Just check if it matches, don't move the finger
}

Token Parser::advance() {
    if (!isAtEnd()) current++; // Move the finger forward by 1
    return previous();         // Return the token we just stepped over
}

bool Parser::match(std::initializer_list<TokenType> types) {
    for (TokenType type : types) {
        if (check(type)) {
            advance(); // We found a match! Move the finger forward!
            return true;
        }
    }
    return false; // No match found
}

Token Parser::consume(TokenType type, const std::string& message) {
    if (check(type)) return advance();
    
    // Grab the token that caused the error so we can tell the user exactly where they messed up!
    Token errorToken = peek();
    
    // If it's the wrong token, the strict teacher throws a massive error WITH the line number!
    throw std::runtime_error("[Line " + std::to_string(errorToken.line) + "] Syntax Error: " + message);
}


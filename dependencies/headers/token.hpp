#pragma once

#include <string>

enum TokenType
{
    KEYWORD,
    IDENTIFIER,

    // Basic
    NIL,
    // Logic
    BOOLEAN,
    // Numbers
    NUMBER,
    // Strings
    STRING,

    // Operators
    OPERATOR,

    // Punctuation
    PUNCTUATION,

    // Special
    EOF_TOKEN, ILLEGAL_CHARACTER
};

struct Token
{
    TokenType tokenType;    // basic declaration (TokenType::NUMBER)
    std::string lexeme;     // actual characters (123)

    // debugging
    int line;
    int column;
};
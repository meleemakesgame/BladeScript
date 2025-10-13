#include "../headers/token.hpp"

void Token::DetectTokenTypeBasedOnLexeme()
{
    // KEYWORDS
    // Variables
    // Basic
    if (lexeme == "nil")
    {
        tokenType = TokenType::KEYWORD;
        return;
    }

    // Modifiers
    else if (lexeme == "unsigned")
    {
        tokenType = TokenType::KEYWORD;
        return;
    }
    else if (lexeme == "long")
    {
        tokenType = TokenType::KEYWORD;
        return;
    }
    else if (lexeme == "const")
    {
        tokenType = TokenType::KEYWORD;
        return;
    }

    // Logic
    else if (lexeme == "bool")
    {
        tokenType = TokenType::KEYWORD;
        return;
    }
    // Numbers
    else if (lexeme == "int")
    {
        tokenType = TokenType::KEYWORD;
        return;
    }
    else if (lexeme == "float")
    {
        tokenType = TokenType::KEYWORD;
        return;
    }
    else if (lexeme == "double")
    {
        tokenType = TokenType::KEYWORD;
        return;
    }

    // Strings
    else if (lexeme == "str")
    {
        tokenType = TokenType::KEYWORD;
        return;
    }

    // Conditionals
    else if (lexeme == "if")
    {
        tokenType = TokenType::KEYWORD;
        return;
    }
    else if (lexeme == "then")
    {
        tokenType = TokenType::KEYWORD;
        return;
    }
    else if (lexeme == "else")
    {
        tokenType = TokenType::KEYWORD;
        return;
    }
    else if (lexeme == "elseif")
    {
        tokenType = TokenType::KEYWORD;
        return;
    }

    // Debug
    else if (lexeme == "print")
    {
        tokenType = TokenType::KEYWORD;
        return;
    }
    else if (lexeme == "warn")
    {
        tokenType = TokenType::KEYWORD;
        return;
    }
    else if (lexeme == "error")
    {
        tokenType = TokenType::KEYWORD;
        return;
    }

    // OPERATORS
    // Logical
    else if (lexeme == "==") // EQUAL
    {
        tokenType = TokenType::OPERATOR;
        return;
    }
    else if (lexeme == "!=") // NOT EQUAL
    {
        tokenType = TokenType::OPERATOR;
        return;
    }
    else if (lexeme == "!") // NOT
    {
        tokenType = TokenType::OPERATOR;
        return;
    }
    else if (lexeme == "&&") // AND
    {
        tokenType = TokenType::OPERATOR;
        return;
    }
    else if (lexeme == "!&") // NAND
    {
        tokenType = TokenType::OPERATOR;
        return;
    }
    else if (lexeme == "||") // OR
    {
        tokenType = TokenType::OPERATOR;
        return;
    }
    else if (lexeme == "!|") // NOR
    {
        tokenType = TokenType::OPERATOR;
        return;
    }
    else if (lexeme == "|>") // XOR
    {
        tokenType = TokenType::OPERATOR;
        return;
    }
    else if (lexeme == "<|") // XNOR
    {
        tokenType = TokenType::OPERATOR;
        return;
    }
    // Arithmetical
    else if (lexeme == "+") // Add
    {
        tokenType = TokenType::OPERATOR;
        return;
    }
    else if (lexeme == "-") // Subtract
    {
        tokenType = TokenType::OPERATOR;
        return;
    }
    else if (lexeme == "*") // Multiply
    {
        tokenType = TokenType::OPERATOR;
        return;
    }
    else if (lexeme == "/") // Divide
    {
        tokenType = TokenType::OPERATOR;
        return;
    }
    else if (lexeme == "%") // Modulo
    {
        tokenType = TokenType::OPERATOR;
        return;
    }
    else if (lexeme == "^") // Power
    {
        tokenType = TokenType::OPERATOR;
        return;
    }
    // Other
    else if (lexeme == "=") // Assignment
    {
        tokenType = TokenType::OPERATOR;
        return;
    }

    // IDENTIFIERS

    // COMMENTS
    else if (lexeme == "//")
    {
        tokenType = TokenType::COMMENT;
        return;
    }

    // PUNCTUATION
    else if (lexeme == "`")
    {
        tokenType = TokenType::PUNCTUATION;
        return;
    }
    else if (lexeme == "~")
    {
        tokenType = TokenType::PUNCTUATION;
        return;
    }
    else if (lexeme == "!")
    {
        tokenType = TokenType::PUNCTUATION;
        return;
    }
    else if (lexeme == "@")
    {
        tokenType = TokenType::PUNCTUATION;
        return;
    }
    else if (lexeme == "#")
    {
        tokenType = TokenType::PUNCTUATION;
        return;
    }
    else if (lexeme == "$")
    {
        tokenType = TokenType::PUNCTUATION;
        return;
    }
    else if (lexeme == "&")
    {
        tokenType = TokenType::PUNCTUATION;
        return;
    }
    else if (lexeme == "(")
    {
        tokenType = TokenType::PUNCTUATION;
        return;
    }
    else if (lexeme == ")")
    {
        tokenType = TokenType::PUNCTUATION;
        return;
    }
    else if (lexeme == "_")
    {
        tokenType = TokenType::PUNCTUATION;
        return;
    }
    else if (lexeme == "{")
    {
        tokenType = TokenType::PUNCTUATION;
        return;
    }
    else if (lexeme == "}")
    {
        tokenType = TokenType::PUNCTUATION;
        return;
    }
    else if (lexeme == "[")
    {
        tokenType = TokenType::PUNCTUATION;
        return;
    }
    else if (lexeme == "]")
    {
        tokenType = TokenType::PUNCTUATION;
        return;
    }
    else if (lexeme == "|")
    {
        tokenType = TokenType::PUNCTUATION;
        return;
    }
    else if (lexeme == ";")
    {
        tokenType = TokenType::PUNCTUATION;
        return;
    }
    else if (lexeme == ":")
    {
        tokenType = TokenType::PUNCTUATION;
        return;
    }
    else if (lexeme == "'")
    {
        tokenType = TokenType::PUNCTUATION;
        return;
    }
    else if (lexeme == ",")
    {
        tokenType = TokenType::PUNCTUATION;
        return;
    }
    else if (lexeme == ".")
    {
        tokenType = TokenType::PUNCTUATION;
        return;
    }
    else if (lexeme == "?")
    {
        tokenType = TokenType::PUNCTUATION;
        return;
    }
    else if (lexeme == "/")
    {
        tokenType = TokenType::PUNCTUATION;
        return;
    }
}
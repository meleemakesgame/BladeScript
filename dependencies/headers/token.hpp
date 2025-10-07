#include <vector>
#include <string>

enum TokenType
{
    // Variables
    // Basic
    INDENTIFIER,
    ASSIGN,
    // Modifiers
    CONST,
    LONG,
    SIGNED,
    UNSIGNED,
    // Logic
    BOOLEAN,
    // Numbers
    INTEGER, FLOAT, DOUBLE,
    // Strings
    STRING, CHARACTER, CONCATENATION,

    // Literals
    // Basic
    INDENTIFIER_LITERAL,
    // Logic
    BOOLEAN_LITERAL,
    // Numbers
    INTEGER_LITERAL, FLOAT_LITERAL, DOUBLE_LITERAL,
    // Strings
    STRING_LITERAL, CHARACTER_LITERAL,

    // Conditional Keywords
    IF, THEN, ELSE, ELSEIF,
    // Logic Keywords
    NOT_LOGIC, AND_LOGIC, NAND_LOGIC,
    // Operators
    // Logical
    EQUAL, NOT_EQUAL, GREATER_THAN, LESS_THAN, GREATER_EQUAL, LESS_EQUAL,
    // Arithmetical
    ADD, SUBTRACT, MULTIPLY, DIVIDE, MODULO, EXPONENT,

    // Loops
    FOR, WHILE, DO,

    // Punctuation
    FORWARD_SLASH, BACKWARD_SLASH, PERIOD, 
    COMMA, SEMICOLON, COLON, 
    RPAREN, LPAREN, RBRACE, LBRACE, RCURLY, LCURLY, 
    QUOTE_MARK, DOUBLE_QUOTE_MARK,
    EXCLAIMATION_MARK, AT_SYMBOL, POUND_SYMBOL, AND_SYMBOL, ASTERISK_SYMBOL,
    UNDERSCORE_SYMBOL, GRAVE_ACCENT_SYMBOL, TILDE_SYMBOL,

    // Files & other stuff
    INCLUDE,
    DEFINE,

    // Debug
    PRINT, WARN, ERROR,

    // Special
    EOF_TOKEN, ILLEGAL
};

struct Token
{
    TokenType tokenType;
    std::string lexeme;

    int line;
    int column;
};
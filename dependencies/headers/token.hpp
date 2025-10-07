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
    STRING, CHARACTER,

    // Literals
    // Basic
    NIL,
    // Logic
    BOOLEAN_LITERAL,
    // Numbers
    INTEGER_LITERAL, FLOAT_LITERAL, DOUBLE_LITERAL,
    // Strings
    STRING_LITERAL, CHARACTER_LITERAL,

    // Conditional Keywords
    IF, THEN, ELSE, ELSEIF, RETURN,
    // Logic Keywords
    NOT_LOGIC, AND_LOGIC, NAND_LOGIC,
    OR_LOGIC, NOR_LOGIC, XOR_LOGIC, XNOR_LOGIC,

    // Operators
    // Logical
    EQUALS, NOT_EQUALS, GREATER_THAN, LESS_THAN, GREATER_EQUALS, LESS_EQUALS,
    // Arithmetical
    ADD, SUBTRACT, MULTIPLY, DIVIDE, MODULO, EXPONENT,
    // Strings
    STRING_CONCATENATION, STRING_NEW_LN,

    // Functions
    FUNCTION, FUNCTION_INDENTIFIER,

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
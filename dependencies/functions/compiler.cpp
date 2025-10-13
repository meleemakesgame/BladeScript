#include "../headers/compiler.hpp"

LuaPlusPlusFile::LuaPlusPlusFile(std::string pFileDir, std::string pFilePath)
{
    std :: cout << "Creating L++ File Class" << std::endl;
    fileDir = pFileDir;
    filePath = pFilePath;
}

// Helper Function
std::vector<std::string> splitStringByDelimiter(std::string& s, const char* delimiter) {
    std::vector<std::string> tokens;
    std::string current_s = s; // Create a mutable copy
    size_t pos = 0;
    std::string token;

    while ((pos = current_s.find(delimiter)) != std::string::npos) {
        token = current_s.substr(0, pos);
        tokens.push_back(token);
        current_s.erase(0, pos + strlen(delimiter)); // Add size of the delimiter to remove the delimiter
    }

    tokens.push_back(current_s); // Add the last token

    return tokens;
}

void LuaPlusPlusFile::CompileIntoCPP()
{
    std :: cout << "Compiling L++ File: " << filePath << ".lpp" << std::endl;
    std::ifstream inputFile(fileDir + "/" + filePath + ".lpp");
    if (!inputFile.is_open())
    {
        std :: cout << "L++COMPILER::ERROR; Could not open Input File!" << std::endl;
        return;
    }

    std :: cout << "Converting L++ File to C++: " << "bin/" << filePath << ".cpp" << std::endl;
    std :: cout << "Generating main() function tokens" << std::endl;
    // Generate "int main()" function tokens
    Token main_func_type;
    main_func_type.tokenType = TokenType::KEYWORD;
    main_func_type.lexeme = "int";
    Token main_func_name;
    main_func_name.tokenType = TokenType::IDENTIFIER;
    main_func_name.lexeme = "main";
    Token main_func_arg_r_paren;
    main_func_arg_r_paren.lexeme = "(";
    main_func_name.tokenType = TokenType::PUNCTUATION;
    Token main_func_arg_l_paren;
    main_func_arg_l_paren.lexeme = ")";
    main_func_name.tokenType = TokenType::PUNCTUATION;
    Token main_func_arg_r_curly;
    main_func_arg_r_curly.lexeme = "{";
    main_func_name.tokenType = TokenType::PUNCTUATION;
    Token main_func_arg_l_curly;
    main_func_arg_l_curly.lexeme = "}";
    main_func_name.tokenType = TokenType::PUNCTUATION;

    tokens.insert(tokens.begin(), main_func_type);
    tokens.insert(tokens.begin() + 1, main_func_name);
    tokens.insert(tokens.begin() + 2, main_func_arg_r_paren);
    tokens.insert(tokens.begin() + 3, main_func_arg_l_paren);
    tokens.insert(tokens.begin() + 4, main_func_arg_r_curly);

    while (std::getline(inputFile, line))
    {
        if (!(line[0] == '/' && line[1] == '/')) // First 2 charcters are '//'
        {
            if (line.length() != 0) // Empty line
            {
                line.push_back(';');
                std :: cout << line << std::endl;
                std::stringstream ss(line);
                Token token;

                // Tokenize by whitespace
                while (ss >> token.lexeme)
                {
                    tokens.push_back(token);
                }

                std :: cout << "Finished Conversion, Starting debug detection" << std::endl;
                // Detect "print()", "warn()", or "error()" statements
                if ((line.find("print") != std::string::npos) || (line.find("warn") != std::string::npos) || (line.find("error") != std::string::npos))
                {
                    std :: cout << "Including iostream file at the beginning of the file" << std::endl;
                    Token pound;
                    pound.tokenType = TokenType::PUNCTUATION;
                    pound.lexeme = "#";
                    Token include;
                    include.tokenType = TokenType::KEYWORD;
                    include.lexeme = "include";
                    Token first_symbol;
                    first_symbol.tokenType = TokenType::PUNCTUATION;
                    first_symbol.lexeme = "<";
                    Token file;
                    file.tokenType = TokenType::IDENTIFIER;
                    file.lexeme = "iostream";
                    Token last_symbol;
                    last_symbol.tokenType = TokenType::PUNCTUATION;
                    last_symbol.lexeme = ">";

                    tokens.insert(tokens.begin(), pound);
                    tokens.insert(tokens.begin() + 1, include);
                    tokens.insert(tokens.begin() + 2, first_symbol);
                    tokens.insert(tokens.begin() + 3, file);
                    tokens.insert(tokens.begin() + 4, last_symbol);

                    // Find & replace the print/warn/error statements
                    // print()
                    if (line.find("print") != std::string::npos)
                    {
                        std::cout<<"found print"<<std::endl;
                        line.replace(line.find("print"), 12, "std::cout<<");
                    }
                }
            }
        }
    }

    tokens.insert(tokens.end(), main_func_arg_l_curly);

    std :: cout << "Closing Input File, Conversion completed" << std::endl;
    inputFile.close();

    // Print Tokenized File
    for (Token t : tokens)
    {
        std :: cout << t.lexeme << std::endl;
    }

    // Write to File
    std :: cout << "Converting Generated Tokens into a C++ File" << std::endl;
    std::ofstream outputFile("C:\\Users\\Rdepa29\\OneDrive - MICDS\\CodeProjects\\C++\\VSCode\\Lua++\\bin\\" + filePath + ".cpp");

    if (!outputFile.is_open())
    {
        std :: cout << "L++COMPILER::ERROR; Could not open Output File!" << std::endl;
        return;
    }

    Token lastT;
    for (Token t : tokens)
    {
        t.DetectTokenTypeBasedOnLexeme();
        std::cout << t.tokenType << std::endl;
        if (t.lexeme[t.lexeme.length() - 1] == ';' || t.lexeme == "{")
        {
            outputFile << t.lexeme << std::endl;
        }
        else if (t.lexeme == "<" || t.lexeme == "#" || t.lexeme == "(" ||(lastT.lexeme == "<" && t.tokenType == TokenType::IDENTIFIER))
        {
            outputFile << t.lexeme;
        }
        else if (t.lexeme == ">")
        {
            outputFile << t.lexeme << std::endl;
        }
        else
        {
            outputFile << t.lexeme << " ";
        }
        lastT = t;
    }
}
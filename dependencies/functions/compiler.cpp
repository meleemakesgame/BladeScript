#include "../headers/compiler.hpp"

LuaPlusPlusFile::LuaPlusPlusFile(std::string pFilePath)
{
    filePath = pFilePath;
}

void LuaPlusPlusFile::CompileIntoCPP()
{
    std::ifstream inputFile(filePath);
    if (!inputFile.is_open())
    {
        std :: cerr << "L++COMPILER::ERROR; Could not open Input File!" << std::endl;
        return;
    }

    while (std::getline(inputFile, line))
    {
        std::stringstream ss(line);
        Token token;

        // Tokenize by whitespace
        while (ss >> token.lexeme)
        {
            tokens.push_back(token);
        }
    }

    inputFile.close();

    // print Tokenized File
    for (Token t : tokens)
    {
        std :: cout << t.lexeme << std::endl;
    }
}
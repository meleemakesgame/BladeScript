#pragma once

#include <fstream>
#include <vector>
#include <sstream>
#include <cstring>
#include <iostream>

#include "token.hpp"

class LuaPlusPlusFile
{
    public:
        std::string fileDir;
        std::string filePath;

        std::string line;
        std::vector<Token> tokens;

        // Constructor
        LuaPlusPlusFile(std::string pFileDir, std::string pFilePath);

        // Compiler Method
        void CompileIntoCPP();
};
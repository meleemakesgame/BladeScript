#pragma once

#include <fstream>
#include <vector>
#include <sstream>

#include "token.hpp"

class LuaPlusPlusFile
{
    public:
        std::string filePath;
        std::vector<Token> tokens;
};
#include <iostream>
#include "../dependencies/headers/compiler.hpp"

int main()
{
    std :: cout << "Running L++ Compiler" << std :: endl;
    LuaPlusPlusFile file("../info/syntax.lpp");
    file.CompileIntoCPP();
    return 0;
}
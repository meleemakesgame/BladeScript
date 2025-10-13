#include <iostream>
#include "../dependencies/headers/compiler.hpp"

int main()
{
    std :: cout << "Running L++ Compiler" << std :: endl;
    LuaPlusPlusFile file("C:\\Users\\Rdepa29\\OneDrive - MICDS\\CodeProjects\\C++\\VSCode\\Lua++\\info", "basic");
    file.CompileIntoCPP();
    return 0;
}
#include <iostream>
#include <fstream>
#include "sym_assembler.h"
#include "OLED.h"

int main()
{
    std::cout << "pre-main" << std::endl;
    Symbol VLine(0);
    VLine.One();
    Symbol &one(VLine);
    Number Ein(one);
    Ein.Drawing();
    std::cout.flush();
    std::cout << "main" << std::endl;
};


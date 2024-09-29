#include <iostream>
#include <fstream>
#include "sym_assembler.h"
#include "OLED.h"

int main()
{
    std::cout << "pre-main" << std::endl;
    Symbol VLine(0);
    /*Symbol &one(VLine);
    Number Ein(one);
    Ein.Drawing();
    std::cout.flush();
    std::cout << "main" << std::endl;
    */
    Changeable_Array& Tmp {*(*(VLine.Get_Private_Part()))};
    std::cout << *(Tmp.CoordValues(4)) << std::endl;
    //std::cout << *(Tmp.CoordValues(3)) << *(Tmp.CoordValues(3) + 1) << std::endl;
};


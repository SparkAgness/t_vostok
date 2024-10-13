#include <iostream>
#include <memory>
#include <fstream>
#include "sym_assembler.h"
#include "OLED.h"

int main()
{
    std::cout << "pre-main" << std::endl;
    Symbol VLine(0);
    VLine.One();
    std::shared_ptr<Changeable_Array> One = VLine.Get_Coords_Obj();
    int shar[2] {*(One->CoordValues(124)), *(One->CoordValues(124) + 1)};
    std::cout << *shar << " " << *(shar + 1) << std::endl;
    std::cout << One->GetLenght() << std::endl;
};


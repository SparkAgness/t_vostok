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
   /* 
    std::shared_ptr<Changeable_Array> One = VLine.Get_Coords_Obj();
    int lim = One->GetLenght();
    for (int i = 0; i < lim; ++i) {
        int shar[2] {*(One->CoordValues(i)), *(One->CoordValues(i) + 1)};
        std::cout << *shar << " " << *(shar + 1) << " | ";
	if (!(i%5)) std::cout << "\n";
    }
    std::cout << "maximum X cell is: " << One->MinMax(true, true) << " maximum Y cell is: " << One->MinMax(false, true) << std::endl;
    std::cout << "minimum X cell is: " << One->MinMax(true, false) << " minimum Y cell is: " << One->MinMax(false, false) << std::endl;
    std::cout << "minimum X, maximum Y cell's number is: " << One->MinMax_Cell(true, false, One->MinMax(false, true)) << std::endl;
    std::cout << "maximum X, minimum Y cell's number is: " << One->MinMax_Cell(true, true, One->MinMax(false, false)) << std::endl;
    std::cout << "maximum X, maximum Y cell's number is: " << One->MinMax_Cell(true, true, One->MinMax(false, true)) << std::endl;
   */
};


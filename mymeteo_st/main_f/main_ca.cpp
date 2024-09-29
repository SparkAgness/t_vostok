#include <iostream>
#include "Change_Arr.h"

int main()
{
    Changeable_Array One(3, 15);
    int tmp[2] {3, 5};
    std::cout << *(One.CoordValues(0)) << ", " << *(One.CoordValues(0) + 1) << " lenght is: " << One.GetLenght() << std::endl;
    One.PushBack(tmp);
    std::cout << *(One.CoordValues(0)) << ", " << *(One.CoordValues(0) + 1) << " lenght is: " << One.GetLenght() << std::endl;
    std::cout << *(One.CoordValues(1)) << ", " << *(One.CoordValues(1) + 1) << " lenght is: " << One.GetLenght() << std::endl;
   

}

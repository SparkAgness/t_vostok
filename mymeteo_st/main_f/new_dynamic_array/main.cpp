#include <iostream>
#include "change_arr_.h"

using namespace changeable_array;

int main()
{
    Array a(1, 3);
    std::cout << a.TestLeftRight() << std::endl;
    a.PushBack(4, 4);
    std::cout << "From 1st PushBack: " << a.GetLastCoord(true) << " " << a.GetLastCoord(false) << std::endl;
    std::cout << a.TestLeftRight() << std::endl;
    a.PushBack(25, 33);
    std::cout << a.GetFirstCoord(true) << " " << a.GetFirstCoord(false) << std::endl;
    std::cout << "From 2nd PushBack: " << a.GetLastCoord(true) << " " << a.GetLastCoord(false) << std::endl;
    std::cout << a.TestLeftRight() << std::endl;
    std::cout << a.GetFirstCoord(true) << " " << a.GetFirstCoord(false) << std::endl;
    std::cout << a.GetIndexCoord(true, 2) << " " << a.GetIndexCoord(false, 2) << std::endl;
    //a.GetIndexCoord(false, 2);
    
}
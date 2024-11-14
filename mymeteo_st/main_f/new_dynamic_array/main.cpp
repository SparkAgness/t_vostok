#include <iostream>
#include "change_arr_.h"

using namespace changeable_array;

int main()
{
    Array a(1, 3);
    a.PushBack(4, 4);
    std::cout << a.GetFirstCoord(true) << " " << a.GetFirstCoord(false) << std::endl;
    std::cout << a.GetLastCoord(true) << " " << a.GetLastCoord(false) << std::endl;
    
}
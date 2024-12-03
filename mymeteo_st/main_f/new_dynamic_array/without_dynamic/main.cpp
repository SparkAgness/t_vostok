#include <iostream>
#include "change_arr_.h"

using namespace changeable_array;

int main()
{
    Array tmp(3, 4);
    //tmp.Test();
    tmp.PushBack(13, 14);
    //tmp.Test();
    //std::cout << tmp.GetFirstCoord(true) << " " << tmp.GetFirstCoord(false) << std::endl;
    //std::cout << tmp.GetLastCoord(true) << " " << tmp.GetLastCoord(false) << std::endl;
    tmp.PushBack(113, 114);
    tmp.PushBack(1113, 1114);
    //tmp.Test();
    //std::cout << tmp.GetFirstCoord(true) << " " << tmp.GetFirstCoord(false) << std::endl;
    //std::cout << tmp.GetSecondCoord(true) << " " << tmp.GetSecondCoord(false) << std::endl;
    //std::cout << tmp.GetLastCoord(true) << " " << tmp.GetLastCoord(false) << std::endl;    
    //tmp.BackTest();
    //std::cout << tmp.GetIndexCoord(true, 0) << " " << tmp.GetIndexCoord(false, 0) << "\n";
    std::cout << tmp.GetIndexCoord(true, 0) << " " << tmp.GetIndexCoord(false, 0) << "\n";
    std::cout << tmp.GetIndexCoord(true, 1) << " " << tmp.GetIndexCoord(false, 1) << "\n";
    std::cout << tmp.GetIndexCoord(true, 2) << " " << tmp.GetIndexCoord(false, 2) << "\n";
    std::cout << tmp.GetIndexCoord(true, 3) << " " << tmp.GetIndexCoord(false, 3) << "\n";
}
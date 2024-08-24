#include <exception>
#define "sys_assembler.h"

#define X_MIDDLE 14
#define Y_MIDDLE 13

void Symbol::Corner::Fig_Creater() override
{
    int y_beg = 2, y_end = 5, x_beg = sum_offset_, x_end = sum_offset + 3; 
    for (int y = y_beg; y <= y_end; ++y) {
        switch (y) {
            case y_beg: {for (int x = x_beg+1; x <= x_end; ++x) {int tmp[2] {x, y}; coord_.PushBack(tmp); break;}}
            case y_beg+1: {for (int x = x_beg; x < x_end - 1; ++x) {int tmp[2] {x, y}; coord_PushBack(tmp); break;}}
            default: {int tmp[2] {x_beg, y}; coord_PushBack(tmp); break;}
        }
    }
};
 
void Symbol::Corner::Rotate_AgainstCW(int yield = 1) override
{
    int len = coord_.GetLenght();
    for (int j = 0; j < yield; ++j) {
        for (int i = 0; i < len; ++i) {
            int exchangeable = *(*(coord_ + i));
            *(*(coord_ + i)) = *(*(coord_ + i) + 1);
            *(*(coord_ + i) + 1) = 1 - exchangeable + side_;
        }
    }
};

void Symbol::Up_QuartCircle::FigCreater() override
{
    int y_beg = 2, y_end = Y_MIDDLE/2 + 1, x_beg = sum_offset_, x_end = X_MIDDLE;
    for (int y = y_beg; y <= y_end; ++y) {
        switch(y) {
            case y_beg: {for (int x = x_beg + 4; x <= x_end; ++x){int tmp[2] {x, y}; coord_.PushBack(tmp); break;}}
            case y_beg + 1: {for (int x = x_beg + 2; x <= x_end; ++x){int tmp[2] {x, y}; coord_.PushBack(tmp); break;}}
            case y_beg + 2: {for (int x = x_beg + 1; x <= x_end - 3; ++x){int tmp[2] {x, y}; coord_.PushBack(tmp); break;}}
            default: {for (int x = x_beg; x <= x_end - 4; ++x){int tmp[2] {x, y}; coord_.PushBack(tmp); break;}}
        }
    }
};

void Symbol::Up_QuartCircle::Mirror(bool horiz, bool vertic) override
{
    try {Mirroring(horiz, vertic);}
    catch (Wrong_Up_QuartCircle&) {Mirroring(0, 1);}
};

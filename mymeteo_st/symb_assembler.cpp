#include <exception>
#define "sym_assembler.h"

#define X_MIDDLE 14
#define Y_MIDDLE 13

void Symbol::Fill_Erase_Array(int choose_corner, bool one_row)
//choose_corner = 1, left-up corner, 2 - right-up, 3 - right-down, 4 - left-down
//one_row = true, erasing one cell, false - erasing three cells
{
    bool x, maxi;
    if (x && maxi) 
    coords_.MinMax(x, maxi);
};

void Symbol::Horizontal_Ln::Other_Line_Creater(bool up = true) //by default is up-side line
{
    y_beg_end[2] {};
    if (up) { *y_beg_end = 2; *(y_beg_end + 1) = *y_beg_end + width_;} 
    else {*y_beg_end = Y_MIDDLE*2 - width_; *(y_beg_end + 1) = Y_MIDDLE*2;}
    for (int y = *y_beg_end; y <= *(y_beg_end + 1); ++y) {
        for(int x = sum_offset_; x <= sum_offset_ + Symbol::s_width; ++x) {tmp[2] {x, y}; coords_.PushBack(tmp);}
    }
};

void Symbol::Horizontal_Ln::Fig_Creater() override //horizontal line at the middle of field
{
    int y_beg = Y_MIDDLE - width_/2, y_end = Y_MIDDLE + width_/2, x_beg = sum_offset_, x_end = sum_offset_ + Symbol::s_width_;
    for (int y = y_beg; y <= y_end; ++y) {
        for (int x = x_beg; x <= x_end; ++x) {tmp[2] {x, y}; coords_.PushBack(tmp);}
    }
};

void Symbol::Vertical_Ln::Zero_Creater(bool by_left = true)
//if by_left is true - there's left line created .| , false - there's right line = . |
{
    int x_beg_end[2];
    int y_beg = 2, y_end = Y_MIDDLE * 2;
    if (by_left) {*x_beg_end = sum_offset_; *(x_beg_end + 1) =  *(sum_offset_) + width_;}
    else {*x_beg_end = sum_offset + 2*width_; *(x_beg_end + 1) = *(x_beg_end) + width_;}
    for (int y = y_beg; y <= y_end; ++y) {
        for (int x = *(x_beg_end); x <= *(x_beg_end + 1); ++x) {int tmp[2] {x, y}; coords_.PushBack(tmp);}
    }
};

void Symbol::Vertical_Ln::Seven_Creater()
{
    int y_beg = Y_MIDDLE - 8, y_end = Y_MIDDLE*2, x_beg = sum_offset_ + X_MIDDLE + 7, x_end = sum_offset_ + X_MIDDLE - 7, i = 0;
    for (int y = y_beg; y <= y_end; ++y) {
        for (int x = x_end - i; x >= x_beg; --x) {
            tmp[2] {x, y};
            coords_.PushBack(tmp);
            }
        if (!(y%2)) {i += 1;}
        }

};

void Symbol::Vertical_Ln::Fig_Creater() override
{
    int y_beg = 2, y_end = Y_MIDDLE*2, x_beg = sum_offset_ + X_MIDDLE - 2, x_end = sum_offset_ + X_MIDDLE + 2;
    for (int y = y_beg; y <= y_end; ++y) {
        for (int x = x_beg; x <= x_end; ++x) {int tmp[2] {x, y}; coord_.PushBack(tmp);}
    }
};

void Symbol::Down_QuartCircle::Mirror(bool hor = true, bool vert = false) override
{
    int arr_lengh = coord_.GetLenght();
    if (hor && !vert) {
        for (int i = 0; i < arr_lengh; ++i) {
            int val = *(coord_.CoordValues(i));
            coord_.ChangeMember(i, X_MIDDLE*2 - val);}
    } else if (!hor && vert) {
            for (int i = 0; i < arr_lengh; ++i) {
                int val = *(coord_.CoordValues(i) + 1);
                coord_.ChangerMember(i, true, 2*(Y_MIDDLE + 1) - val);}
};

void Symbol::Central_Point::Fig_Creater() override
{
    int y_beg = Y_MIDDLE, y_end = Y_MIDDLE + 1, x_beg = sum_offset_, x_end = sum_offset + 3;
    for (int y = y_beg; y <= y_end; ++y) {
        for (int x = x_beg; x <= x_end; ++x) {int tmp[2] {x, y}; coord_.PushBack(tmp);}
    }
};

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

void Symbol::Corner::DownCorner()
{
    int lenght = coord_.GetLenght;
    for (int i = 0; i < lenght; ++i) {
        coord_.ChangeMember(i, true, *(coord_.CoordValues(i)))
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
    catch (Wrong_Up_QuartCircle& ex) {this->Mirroring(0, 1);}////
};

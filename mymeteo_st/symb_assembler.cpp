#include <exception>
#include "sym_assembler.h"
#include "Change_Arr.h"

#define X_MIDDLE 14
#define Y_MIDDLE 13

void Symbol::Two()
{

};

void Symbol::One()
{
    Vertical_Ln For_One(*this);
    For_One.Fig_Creater();
    For_One.Erase_Corner(1, true);
    figure_kit_ = *(For_One.GetCoord());
};

void Symbol::Symbol_Part::Erase_Corner(int corner, bool rows)
{
    Fill_Erase_Array(corner, rows);
    coords_.ChangeMember(*(erase_array_.CoordValues(0)), 0, false);
    coords_.ChangeMember(*(erase_array_.CoordValues(0)), 0, true);
    if (rows) {
        coords_.ChangeMember(*(erase_array_.CoordValues(1)), 0, false);
        coords_.ChangeMember(*(erase_array_.CoordValues(1)), 0, true);
        coords_.ChangeMember(*(erase_array_.CoordValues(1) + 1), 0, false);
        coords_.ChangeMember(*(erase_array_.CoordValues(1) + 1), 0, true);
    }

};

void Symbol::Symbol_Part::Fill_Erase_Array(int choose_corner, bool one_row)
//choose_corner = 1, left-up corner, 2 - right-up, 3 - right-down, 4 - left-down
//one_row = true, erasing one cell, false - erasing three cells
{
    bool x_maxi, y_maxi; //x_maxi=true - finds x maximum, y_max - the same as x_max
    switch (choose_corner) {
        case 1: x_maxi = false; y_maxi = false; break;
	case 2: x_maxi = true; y_maxi = false; break;
        case 3: x_maxi = true; y_maxi = true; break;
        case 4: x_maxi = false; y_maxi = true; break;
    }
    int in = coords_.MinMax(true, x_maxi);
    int push_in = coords_.MinMax_Cell(y_maxi, false, in);
    Changeable_Array one(push_in, 0); 
    erase_array_ = one;
    if (!one_row) {
        int f_x = *(coords_.CoordValues(push_in));
        int f_y = *(coords_.CoordValues(push_in) + 1);
        switch (choose_corner) {
            case 1: {int tmp[2] {coords_.Finding_Index(f_x + 1, f_y), coords_.Finding_Index(f_x, f_y + 1)}; erase_array_.PushBack(tmp); break;}
            case 2: {int tmp[2] {coords_.Finding_Index(f_x - 1, f_y), coords_.Finding_Index(f_x, f_y + 1)}; erase_array_.PushBack(tmp); break;}
            case 3: {int tmp[2] {coords_.Finding_Index(f_x, f_y - 1), coords_.Finding_Index(f_x - 1, f_y)};  erase_array_.PushBack(tmp); break;}
            case 4: {int tmp[2] {coords_.Finding_Index(f_x - 1, f_y), coords_.Finding_Index(f_x, f_y - 1)}; erase_array_.PushBack(tmp); break;}
        }
    }
};

void Symbol::Horizontal_Ln::Other_Line_Creater(bool up = true) //by default is up-side line
{
    int y_beg_end[2] {};
    if (up) { *y_beg_end = 2; *(y_beg_end + 1) = *y_beg_end + width_;} 
    else {*y_beg_end = Y_MIDDLE*2 - width_; *(y_beg_end + 1) = Y_MIDDLE*2;}
    for (int y = *y_beg_end; y <= *(y_beg_end + 1); ++y) {
        for(int x = sum_offset_; x <= sum_offset_ + Symbol::Get_Swidth(); ++x) {int tmp[2] {x, y}; coords_.PushBack(tmp);}
    }
};

void Symbol::Vertical_Ln::Zero_Creater(bool by_left = true)
//if by_left is true - there's left line created .| , false - there's right line = . |
{
    int x_beg_end[2];
    int y_beg = 2, y_end = Y_MIDDLE * 2;
    if (by_left) {*x_beg_end = sum_offset_; *(x_beg_end + 1) =  sum_offset_ + width_;}
    else {*x_beg_end = sum_offset_ + 2*width_; *(x_beg_end + 1) = *(x_beg_end) + width_;}
    for (int y = y_beg; y <= y_end; ++y) {
        for (int x = *(x_beg_end); x <= *(x_beg_end + 1); ++x) {int tmp[2] {x, y}; coords_.PushBack(tmp);}
    }
};

void Symbol::Vertical_Ln::Seven_Creater()
{
    int y_beg = Y_MIDDLE - 8, y_end = Y_MIDDLE*2, x_beg = sum_offset_ + X_MIDDLE + 7, x_end = sum_offset_ + X_MIDDLE - 7, i = 0;
    for (int y = y_beg; y <= y_end; ++y) {
        for (int x = x_end - i; x >= x_beg; --x) {
            int tmp[2] {x, y};
            coords_.PushBack(tmp);
            }
        if (!(y%2)) {i += 1;}
        }

};


void Symbol::Corner::DownCorner()
{
    int lenght = coords_.GetLenght();
    for (int i = 0; i < lenght; ++i) {
        coords_.ChangeMember(i, true, *(coords_.CoordValues(i)));
    }
};



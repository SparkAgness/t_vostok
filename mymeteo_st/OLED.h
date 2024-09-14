#ifndef OLED
#define OLED

#include "SSD1306Wire.h"
#include "sym_assembler.h"

class Number
{
    private:
        int offset_;
        int val_;
        SSD1306Wire& tmp_wire_;
    public:
        Number(int, int, SSD1306Wire&);
        void Drawing(const int [][2] , int) const;
        void SetDisplay() const;
};

void Number::SetDisplay() const
{
    if (1 == this->val_) {this->Drawing(Number::one, 131);}
    if (2 == this->val_) {this->Drawing(Number::two, 171);}
};

void Number::Drawing(const int pt [][2], int size) const
{
    for (int i = 0; i < size; ++i) {
        tmp_wire_.setPixel(*(*(pt + i)) + this->offset_, *(*(pt + i) + 1));
    }
};

Number::Number(int offset, int val, SSD1306Wire& tmp_wire) : offset_(offset), val_(val), tmp_wire_(tmp_wire) {};

#endif

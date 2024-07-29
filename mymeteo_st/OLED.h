#ifndef OLED
#define OLED

#include "SSD1306Wire.h"

class Number
{
    private:
        static inline const int one[] = 
        [[15,2], [16, 2], [17, 2], 
        [14, 3], [15, 3], [16, 3], [17, 3], 
        [13, 4], [14, 4], [15, 4], [16, 4], [17, 4], 
        [12, 5], [13, 5], [14, 5], [15, 5], [16, 5], [17, 5], 
        [11, 6], [12, 6], [13, 6], [14, 6], [15, 6], [16, 6], [17, 6], 
        [10, 7], [11, 7], [12, 7], [13, 7], [14, 7], [15, 7], [16, 7], [17, 7],
        [10, 8], [11, 8], [12, 8], [13, 8], [14, 8], [15, 8], [16, 8], [17, 8], 
	[13, 9], [14, 9], [15, 9], [16, 9], [17, 9], 
	[13, 10], [14, 10], [15, 10], [16, 10], [17, 10], 
	[13, 11], [14, 11], [15, 11], [16, 11], [17, 11],
        [13, 12], [14, 12], [15, 12], [16, 12], [17, 12],
        [13, 13], [14, 13], [15, 13], [16, 13], [17, 13], 
        [13, 14], [14, 14], [15, 14], [16, 14], [17, 14], 
        [13, 15], [14, 15], [15, 15], [16, 15], [17, 15], 
        [13, 16], [14, 16], [15, 16], [16, 16], [17, 16], 
        [13, 17], [14, 17], [15, 17], [16, 17], [17, 17], 
        [13, 18], [14, 18], [15, 18], [16, 18], [17, 18], 
        [13, 19], [14, 19], [15, 19], [16, 19], [17, 19], 
        [13, 20], [14, 20], [15, 20], [16, 20], [17, 20], 
        [13, 21], [14, 21], [15, 21], [16, 21], [17, 21], 
        [13, 22], [14, 22], [15, 22], [16, 22], [17, 22], 
        [13, 23], [14, 23], [15, 23], [16, 23], [17, 23], 
        [13, 24], [14, 24], [15, 24], [16, 24], [17, 24], 
        [13, 25], [14, 25], [15, 25], [16, 25], [17, 25], 
        [13, 26], [14, 26], [15, 26], [16, 26], [17, 26]];

        int offset_;
        int val_;
    public:
        void Drawing(int* , int) const;
        static void SetDisplay(int) const;
};

static void Number::SetDisplay() const
{
    if (1 == this->val_) {this->Drawing(Number::one, sizeof(one)/sizeof(int));}
};

void Number::Drawing(int* pt, int size) const
{
    SSD1306Wire display(0x3c, 12, 13, GEOMETRY_128_32);
    display.clear();
    for (int i = 0; i < size; ++i) {
        display.SetPixel(*((pt + 2)*i) + this->offset_, *((pt + 2)*i + 1) + this->offset_);
    }
    display.display();
};

Number::Number(int offset, int val) : offset_(offset), val_(val);

#endif

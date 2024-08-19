#define "sys_assembler.h"
#define X_MIDDLE 14
#define Y_MIDDLE 13

void Symbol::Corner::Fig_Creater(int offset) override
{
    int y_beg = 2, y_end = 5, x_beg = offset + 7, x_end = offset + 10; 
    for (int y = y_beg; y <= y_end; ++y) {
        switch (y) {
            case y_beg: {for (int x = x_beg+1; x <= x_end; ++x) {int tmp[2] {x, y}; coord_.PushBack(tmp); break;}}
            case y_beg+1: {for (int x = x_beg; x < x_end - 1; ++x) {int tmp[2] {x, y}; coord_PushBack(tmp); break;}}
            default: {int tmp[2] {x_beg, y}; coord_PushBack(tmp); break;}
        }
    }
}
 
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

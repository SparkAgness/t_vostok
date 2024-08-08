/*
Arc sectors sheme:

 1 | 2
 -----
 3 | 4

 */




#ifndef SYMBOL
#define SYMBOL
#define HIGHT 26
#define VERT_QUARTER 7
#define HOR_AXIS 14
#define IN_RAD 4 

#include <Change_Arr.h>

class Symbol final
{
    private:
        int name_;
        Changeable_Array coord_kit_;

        void Draw_UpSector1(int); //OK
        void Draw_UpSector2(int);
        void DrawTwo();

    public:
        Symbol(int);
        void Symb_Drawing(const int);
};

void Symbol::Draw_UpSector2(int offset)
{
    int out_offset = 7;
    int tmp[2] {0, 0};
};

void Symbol::Draw_UpSector1(int offset)
{
    int in_offset = 7;
    int tmp[2] {0, 0};
    for (int y = 2; y <= VERT_QUARTER; ++y) {
        switch(y)
        {
            case 2: for (int x = offset + in_offset + 4; x <= HOR_AXIS; ++x) {tmp[2] {x, y}; this->coord_kit_.PushBack(tmp); break;}
            case 3: for (int x = offset + in_offset + 2; x <= HOR_AXIS; ++x) {tmp[2] {x, y}; this->coord_kit_.PushBack(tmp); break;}
            case 4: for (int x = offset + in_offset + 1; x <= HOR_AXIS - IN_RAD + 1; ++x) {tmp[2]{x,y}; this->coord_kit_.PushBack(tmp); break;} 
            default: for (int x = offset + in_offset; x <= HOR_AXIS - IN_RAD; ++x) {tmp[2]{x,y}; this->coord_kit_.PushBack(tmp); break;} 
            
	}
    }
};

void Symbol::Symb_Drawing(const int name)
{

};

Symbol::Symbol (int type) : name_(type), coord_kit_(0, 0) {};

void Symbol::DrawTwo()
{

};


#endif

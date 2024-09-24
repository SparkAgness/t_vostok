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
        void Draw_UpSector2(int); //OK
        void Draw_UpSector3(int); //OK
        void Draw_UpSector4(int); //OK
        void DrawTwo();

    public:
        Symbol(int);
        void Symb_Drawing(const int);
};

void Symbol::Draw_UpSector4(int offset)
{
    int out_offset = 7;
    int begin_board = offset + HOR_AXIS;
    int end_board = offset + HOR_AXIS + out_offset;
    int tmp[2] {0, 0};
    for (y = VERT_QUATER + 1; y < 2*VERT_QUATER; ++y) {
        switch (y)
        {
            case 11: for (int x = begin_board + IN_RAD - 1; x <= end_board - 1; ++x) {tmp[2] {x, y}; this->coord_kit_.PushBack(tmp); break;}
            case 12: for (int x = begin_board; x <= end_board - 2; ++x) {tmp[2] {x, y}; this->coord_kit_.PushBack(tmp); break;}
	        case 13: for (int x = begin_board; x <= end_board - 4; ++x) {tmp[2] {x, y}; this->coord_kit_.PushBack(tmp); break;} 
            default: for (int x = begin_board + IN_RAD; x <= end_board; ++x) {tmp[2] {x, y}; this->coord_kit_.PushBack(tmp); break;}
       }
    }

};

void Symbol::Draw_UpSector3(int offset)
{
    int in_offset = 7;
    int begin_board = in_offset + offset;
    int end_board = offset + HOR_AXIS;
    int tmp[2] {0, 0};
    for (y = VERT_QUATER + 1; y < 2*VERT_QUATER; ++y) {
        switch (y) 
        {
            case 11: for (int x = begin_board + 1; x <= end_board - IN_RAD + 1; ++x) {tmp[2]{x,y}; this->coord_kit_.PushBack(tmp); break;} 
            case 12: for (int x = begin_board + 2; x <= end_board; ++x) {tmp[2] {x, y}; this->coord_kit_.PushBack(tmp); break;}
            case 13: for (int x = begin_board + 4; x <= end_board; ++x) {tmp[2] {x, y}; this->coord_kit_.PushBack(tmp); break;}
            default: for (int x = begin_board; x <= end_board - IN_RAD; ++x) {tmp[2]{x,y}; this->coord_kit_.PushBack(tmp); break;} 
        }
    }
};

void Symbol::Draw_UpSector2(int offset)
{
    int out_offset = 7;
    int begin_board = offset + HOR_AXIS;
    int end_board = offset + HOR_AXIS + out_offset;
    int tmp[2] {0, 0};
    for (y = 2; y <= VERT_QUATER; ++y) {
        switch (y)
        {
            case 2: for (int x = begin_board; x <= end_board - 4; ++x) {tmp[2] {x, y}; this->coord_kit_.PushBack(tmp); break;} 
	    case 3: for (int x = begin_board; x <= end_board - 2; ++x) {tmp[2] {x, y}; this->coord_kit_.PushBack(tmp); break;}
            case 4: for (int x = begin_board + IN_RAD - 1; x <= end_board - 1; ++x) {tmp[2] {x, y}; this->coord_kit_.PushBack(tmp); break;}
            default: for (int x = begin_board + IN_RAD; x <= end_board; ++x) {tmp[2] {x, y}; this->coord_kit_.PushBack(tmp); break;}

        }
    }
};

void Symbol::Draw_UpSector1(int offset)
{
    int in_offset = 7;
    int tmp[2] {0, 0};
    int begin_board = offset + in_offset;
    int end_board = offset + HOR_AXIS;
    for (int y = 2; y <= VERT_QUARTER; ++y) {
        switch(y)
        {
            case 2: for (int x = begin_board + 4; x <= end_board; ++x) {tmp[2] {x, y}; this->coord_kit_.PushBack(tmp); break;}
            case 3: for (int x = begin_board + 2; x <= end_board; ++x) {tmp[2] {x, y}; this->coord_kit_.PushBack(tmp); break;}
            case 4: for (int x = begin_board + 1; x <= end_board - IN_RAD + 1; ++x) {tmp[2]{x,y}; this->coord_kit_.PushBack(tmp); break;} 
            default: for (int x = begin_board; x <= end_board - IN_RAD; ++x) {tmp[2]{x,y}; this->coord_kit_.PushBack(tmp); break;} 
            
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

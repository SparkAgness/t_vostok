#ifndef SYMBOL
#define SYMBOL
#define HIGHT 26

#include <Change_Arr.h>

class Symbol final
{
    private:
        int name_;
        Changeable_Array coord_kit_;
        void DrawTwo();

    public:
        Symbol(int);
        void Symb_Drawing(const int);
};

void Symbol::Symb_Drawing(const int name)
{

};

Symbol::Symbol (int type) : name_(type), coord_kit_(0, 0) {};

void Symbol::DrawTwo()
{
    int offset1 = 7, offset2 = 12;
    for (int y = 0; y <= HIGHT; ++y) {
        switch(y) {
            case 2: 
                for (x = 0; x < 7; ++x) {int tmp [2] {x + offset1 + 4, y}; this->coord_kit_.PushBack(tmp);} 
            case 3: 
                for (x = 0; x < 11; ++x) {int tmp[2] {x + offset1 + 2, y}; this->coord_kit_.PushBack(tmp);}
            case 4:
                for (x = 0; x < 14; ++x) {int tmp[2] {x + offset1 + 1, y}; this->coord_kit_.PushBack(tmp);}
            case 5:
                for (x = 0; x < 5; ++x) {int tmp[2] {x + offset1, y}; int tmp2[2] {x + offset2, y}; this->coord_kit_.PushBack(tmp); this->coord_kit_.PushBack(tmp2);}
            case 6: 
                
	}
    }
};


#endif

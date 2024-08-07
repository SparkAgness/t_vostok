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
                this->coord_kit_.
	}
    }
};


#endif

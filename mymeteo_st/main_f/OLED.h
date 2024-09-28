#ifndef OLED
#define OLED
#define DEBUG


#ifndef DEBUG 
    #include "SSD1306Wire.h"
#elifdef DEBUG
    #include <iostream> 
#endif

#include "sym_assembler.h"

class Number final
{
    private:
        Symbol& numb_;
        #ifndef DEBUG
            SSD1306Wire& tmp_wire_;
        #endif
    public:
        #ifndef DEBUG
            Number(Symbol& numb, SSD1306Wire& tmp_wire) : numb_(numb), tmp_wire_(tmp_wire) {};
        #elifdef DEBUG
            Number(Symbol& numb) : numb_(numb) {};
        #endif
        void Drawing() const;
};

void Number::Drawing() const
{
    Changeable_Array& pt = numb_.Get_Array();
    int pt_size = pt.GetLenght();
    
    for (int i = 0; i < pt_size; ++i) {
        #ifndef DEBUG
            tmp_wire_.setPixel(*(pt.CoordValues(i)), *(pt.CoordValues(i) + 1));
        #elifdef DEBUG
//            std::cout << *(pt.CoordValues(i)) << ", " << *(pt.CoordValues(i) + 1) << std::endl;
	    std::cout << "jd" << std::endl;
        #endif
    }
};

#endif

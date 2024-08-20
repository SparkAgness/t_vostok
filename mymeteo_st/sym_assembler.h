#ifndef SYMBASSEMBLY
#define SYMBASSEMBLY

#include "Change_Arr.h"

class Symbol final
{
    private:
        Changeable_Array figure_kit_;
        int offset_;

        class Symbol_Part
        {
            private:

            protected:
                virtual void Rotate_AgainstCW(int) = 0;
                virtual void Fig_Creater() = 0;
                virtual void Mirror(bool, bool) = 0;
            public:
                Symbol_Part(int side) : coords_(0, 0), side_(side) {};
                virtual ~Symbol_Part();
        };

        class Corner : protected Symbol_Part 
        {
            private:
                Changeable_Array coords_;
                int side_;
                int sum_offset_;
            protected:
                void Rotate_AgainstCW(int) override;
                void Fig_Creater(int) override;
            public:
            Corner(int side = 4, in_offset = 7) : coords_(0, 0), side_(side), sum_offset_(in_offset + this->offset_) {};
        };

        class Up_QuartCircle : protected Symbol_Part
        {
            private:
                Changeable_Array coords_;
                int side_;	
                int sum_offset_;
            public:
                Up_QuartCircle(int side, int in_offset = 7) : coords_(0, 0), side_(side), sum_offset_(in_offset + this->offset_) {};
        };

    public:
        Symbol(int offset) : figure_kit_(0, 0), offset_(offset) {};

};

#endif

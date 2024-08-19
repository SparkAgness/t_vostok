#ifndef SYMBASSEMBLY
#define SYMBASSEMBLY

#include "Change_Arr.h"

class Symbol final
{
    private:
        Changeable_Array figure_kit_;

        class Symbol_Part
        {
            private:
                Changeable_Array coords_;
                int side_;
            protected:
                virtual void Rotate_AgainstCW(int) = 0;
                virtual void Fig_Creater(int) = 0;
            public:
                Symbol_Part(int side) : coords_(0, 0), side_(side) {};
                virtual ~Symbol_Part();
       };

       class Corner : protected Symbol_Part 
       {
           private:
               Changeable_Array coords_;
           protected:
               void Rotate_AgainstCW(int) override;
               void Fig_Creater(int) override;
           public:
               Corner(int side = 4) : coords_(0, 0), side_(side) {};
       };

    public:
            Symbol() : figure_kit_(0, 0) {}; 
};

#endif

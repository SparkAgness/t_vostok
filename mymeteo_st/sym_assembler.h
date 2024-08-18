#ifndef SYMBASSEMBLY
#define SYMBASSEMBLY

#include "Change_Arr.h"

class Symbol final
{
    private:
        Changeable_Array figure_kit_;
        class Symbol_Part;
	class Corner : protected Symbol_Part; public:
        Symbol() : figure_kit_(0, 0) {}; 
};

class Symbol::Symbol_Part
{
    private:
        Changeable_Array coords_;
    protected:
        virtual void Rotate_AgainstCW() = 0;
        virtual void Fig_Creater() = 0;
    public:
        Symbol_Part() : coords_(0, 0) {};
        virtual ~Symbol_Part();
};

class Corner : protected Symbol::Symbol_Part
{
    private:
        Changeable_Array coords_;
    protected:
        void Rotate_AgainstCW() override;
        void Fig_Creater(int) override;
    public:
        Corner() : Symbol::Symbol_Part() {};
};

#endif

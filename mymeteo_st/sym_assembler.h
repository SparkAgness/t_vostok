#ifndef SYMBASSEMBLY
#define SYMBASSEMBLY

#include "Change_Arr.h"
#include "number_ass.h"

class Symbol::Symbol_Part
{
    private:
    protected:
        virtual void Rotate_AgainstCW() = 0;
        virtual void Fig_Creater() = 0;
    public:
        virtual ~Symbol();
}

class Corner : protected Symbol::Symbol_Part
{
    private:
        Changeable_Array coords_;
    protected:
        void Rotate_AgainstCW() override;
        void Fig_Creater(int) override;
    public:
        Corner() : coords_(0, 0) {};
};

#endif

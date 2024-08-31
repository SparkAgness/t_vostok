#ifndef ERRORS
#define ERRORS

#include <iostream>
#include <string>
#include "sym_assembler.h"

class Errors
{
    private:
    public:
        Errors() {};
        virtual ~Errors();
    protected:
        virtual void GetError() const = 0;
};

class Wrong_Up_QuartCircle final : protected Errors
{
    private:
        std::string name_;
    public:
	Wrong_Up_QuartCircle(std::string name = "UpQuarter mirror error") : Errors(), name_(name) {};
    protected:
        void GetError() const override
        {
            std::cout << "Method Corner::Mirror() is mistakeable... The method is called with vertical mirroring" << std::endl;
        };
};
#endif

#ifndef ERRORS
#define ERRORS
#include <string>

class Errors
{
    private:
    public:
        Errors() {};
        ~Errors() virtual;
    protected:
        void GetError() const virtual = 0;
}

class Wrong_Up_QuartCircle : protected Errors final
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

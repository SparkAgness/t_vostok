#include <iostream>
#ifndef CHANGEARR
#define CHANGEARR
namespace change_arr {

class Changeable_Array final
{
    private:
        int* body_;
	Changeable_Array* left_;
	Changeable_Array* right_;
    public:
	Changeable_Array() : body_{new int[2]} {left_ = nullptr; right_ = nullptr;};
        Changeable_Array(int x, int y) : body_(new int[2]) {*body_ = x; *(body_ + 1) = y; left_ = nullptr; right_ = nullptr;}; 
        Changeable_Array(Changeable_Array& node) 
        {
            body_ = new int[2] {node.GetBody(false), node.GetBody(true)};
	    left_ = node.GetNodeLink(true);
            right_ = node.GetNodeLink(false);
	};
        ~Changeable_Array() {delete [] body_;};
        
	int GetBody(bool);
        Changeable_Array* GetNodeLink(bool);
		
};
int Changeable_Array::GetBody(bool first)
{
    if (first) return *(body_ + 1);
    return *body_;
};

Changeable_Array* Changeable_Array::GetNodeLink(bool left)
{
    if (left) return left_;
    return right_;
};
}

#endif


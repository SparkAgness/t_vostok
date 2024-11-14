#include <iostream>
#include "change_arr_.h"

using namespace changeable_array;

void Array::PushBack(int x, int y)
{
    if ((0 == last_.GetCoord_(true)) && (0 == last_.GetCoord_(false))) {
        last_.SetCoord(x, y);
    } else {
        ArrNode tmp(x,y);
        std::shared_ptr<ArrNode> tmp_{std::make_shared<ArrNode> (tmp)};
        tmp_->SetBackLink(&first_);
        tmp_->SetForwardLink(nullptr);
        first_.SetForwardLink(&tmp);
        first_ = tmp;    
    }
}

int Array::GetFirstCoord(bool x = true) const
{
    return first_.GetCoord_(x);
};

int Array::GetLastCoord(bool x = true) const
{
    return (last_.GetCoord_(x));
}
int Array::GetIndexCoord(bool, int) const //to do!!!
{
    return 0;
};

#include <iostream>
#include <memory>
#include "change_arr_.h"

using namespace changeable_array;

void Array::PushBack(int x, int y)
{
    ArrNode& first = first_;
    ArrNode& last = last_;
    if ((0 == last_.GetCoord_(true)) && (0 == last_.GetCoord_(false)) && (last_ == *(first_.GetLink()))) {
        last_.SetCoord(x, y);        
    } else { 
        ArrNode tmp;
        ArrNode& ref_tmp = tmp;
        std::shared_ptr<ArrNode> tmp_{std::make_shared<ArrNode> (tmp)};
        tmp_->SetBackLink(first);
        tmp_->SetForwardLink(last);
        tmp_->SetCoord(last_.GetCoord_(true), last_.GetCoord_(false));
        last_.GetLink(false)->SetForwardLink(ref_tmp);
        last_.SetBackLink(ref_tmp);
        last_.SetCoord(x, y);    
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

int Array::GetIndexCoord(bool x, int num) const //to do!!!
{
    ArrNode tmp(first_);
    std::cout << "From getindexcoord first_ is:" << tmp.GetCoord_(true) << " " << tmp.GetCoord_(false) << std::endl;
    for (int i = 0; i < num; ++i) { 
        tmp = *(tmp.GetLink());       
        std::cout << "the num is: " << i << " " << tmp.GetCoord_(true) << " " << tmp.GetCoord_(false) << std::endl;        
    }
    return tmp.GetCoord_(x);
};

#include <iostream>
#include <memory>
#include "change_arr_.h"

using namespace changeable_array;

void Array::PushBack(int x, int y)
{
    ArrNode& first = first_;
    ArrNode& last = last_;
    first.SetForwardLink(last);
    last.SetForwardLink(first); 
    if ((0 == last_.GetCoord_(true)) && (0 == last_.GetCoord_(false))) {
        last_.SetCoord(x, y);       
    } else { 
        ArrNode tmp;
        ArrNode& ref_tmp = tmp;
        std::shared_ptr<ArrNode> tmp_{std::make_shared<ArrNode> (ref_tmp)};
        ref_tmp.SetBackLink(first_);
        #ifdef DEBUG
            std::cout << "FIRST FROM TMP: " << (ref_tmp.GetLink(false))->GetCoord_(true) << " " << (ref_tmp.GetLink(false))->GetCoord_(false) << std::endl;
        #endif
        ref_tmp.SetForwardLink(last);
        #ifdef DEBUG
            std::cout << "LAST FROM TMP: " << (ref_tmp.GetLink())->GetCoord_(true) << " " << (ref_tmp.GetLink())->GetCoord_(false) << std::endl;
            std::cout << "FIRST FROM TMP: " << (ref_tmp.GetLink(false))->GetCoord_(true) << " " << (ref_tmp.GetLink(false))->GetCoord_(false) << std::endl;
        #endif
        ref_tmp.SetCoord(last_.GetCoord_(true), last_.GetCoord_(false));
        last_.GetLink(false)->SetForwardLink(ref_tmp);
        #ifdef DEBUG
            std::cout << "AFTER LINKING NEXT BY 1ST IS: " << (first_.GetLink())->GetCoord_(true) << " " << (first_.GetLink())->GetCoord_(false) << std::endl;
        #endif
        last_.SetBackLink(ref_tmp);
        last_.SetCoord(x, y);  
        tmp.SetForwardLink(last);
        #ifdef DEBUG
            std::cout << "AFTER INIT STRAIGHT LAST IS: " << last_.GetCoord_(true) << " " << last_.GetCoord_(false) << std::endl;
            std::cout << "AFTER INIT MIDDLE FROM LAST IS: " << (last_.GetLink(false))->GetCoord_(true) << " " << (last_.GetLink(false))->GetCoord_(false) << std::endl; 
            std::cout << "AFTER LINKING AND INIT LAST FROM TMP IS: " << (ref_tmp.GetLink())->GetCoord_(true) << " " << (ref_tmp.GetLink())->GetCoord_(false) << std::endl;
        #endif  
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
    ArrNode tmp(last_);
    std::cout << "From getindexcoord last_ is:" << tmp.GetCoord_(true) << " " << tmp.GetCoord_(false) << std::endl;
    for (int i = 0; i < num; ++i) { 
        tmp = *(tmp.GetLink());       
        std::cout << "the num is: " << i << " " << tmp.GetCoord_(true) << " " << tmp.GetCoord_(false) << std::endl;        
    }
    return tmp.GetCoord_(x);
};

int Array::TestLeftRight()
{
    ArrNode a = *(first_.GetLink());
    return a.GetCoord_(true);
}

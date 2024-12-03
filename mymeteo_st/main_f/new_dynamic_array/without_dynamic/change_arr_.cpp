#include <iostream>
#include <memory>
#include "change_arr_.h"

using namespace changeable_array;

void Array::PushBack(int x, int y)
{
    if (0 == last_->x_ && 0 == last_->y_) {
        last_->x_ = x;
        last_->y_ = y;
    } else {
        std::shared_ptr<ArrNode> tmp (new ArrNode);
        tmp->x_ = x;
        tmp->y_ = y;
        tmp->left_ = last_;
        last_->right_ = tmp;
        last_ = tmp;
    }
};

int Array::GetFirstCoord(bool x = true) const
{
    if(x) return first_->x_;
    return first_->y_;
};

int Array::GetLastCoord(bool x = true) const
{
    if(x) return last_->x_;
    return last_->y_;
};

int Array::GetIndexCoord(bool x, int num) const 
{
    std::shared_ptr<ArrNode> tmp = first_;
    if (0 != num) {
        for (int n = 0; n < num; ++n) {
        tmp = tmp->right_;
        }
    }
    if (x) return tmp->x_;
    return tmp->y_;
};

int Array::GetSecondCoord(bool x = true)
{
    if (x) return first_->right_->x_;
    return last_->left_->y_;
};

void Array::Test()
{
    std::cout << "first is: " << first_->x_ << " " << first_->y_ << "\n";
    std::cout << "last is: " << last_->x_ << " " << last_->y_ << " \n";
    std::cout << "after first is: " << first_->right_->x_ << " " << first_->right_->y_ << "\n";
    std::cout << "before last is: " << last_->left_->x_ << " " << last_->left_->y_ << "\n";
};

void Array::BackTest()
{    
    std::cout << "first is: " << first_->x_ << " " << first_->y_ << "\n";
    std::cout << "last is: " << last_->x_ << " " << last_->y_ << " \n";
    std::cout << "middle from last is: " << last_->left_->x_ << " " << last_->left_->y_ << "\n";
    std::cout << "first from last is: " << last_->left_->left_->x_ << " " << last_->left_->left_->y_ << "\n";
};

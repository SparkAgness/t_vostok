#include <iostream>
#include <memory>
#include <stdexcept>
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
}

void Array::DeleteFirst()
{
    first_ = first_->right_;
    first_->left_ = nullptr;
}
void Array::DeleteLast() 
{
    last_ = last_->left_;
    last_->right_ = nullptr;
}

void Array::Delete(std::shared_ptr<ArrNode> Cleared)
{
    if (nullptr == Cleared->left_) {DeleteFirst();}
    else if (nullptr == Cleared->right_) {DeleteLast();}
    else { 
        Cleared->left_->right_ = Cleared->right_;
        Cleared->right_->left_ = Cleared->left_;  
    }  
}
std::shared_ptr<Array::ArrNode> Array::Moving(int index)
{
    if (index < 0) throw -1;
    std::shared_ptr<ArrNode> tmp = first_;
    if (0 == index) {return first_;}
    for (int i = 0; i < index; ++i) {
        tmp = tmp->right_;
        if (nullptr == tmp) {throw std::out_of_range("Out of range");} 
    }
    return tmp;
};

void Array::DeleteSecond()
{
    Delete(first_->right_);
};

void Array::DeleteByIndex(int index) 
{
    std::shared_ptr<ArrNode> del;
    try {
        del = Moving(index);
    } catch(std::out_of_range& ex) {
        del = last_;
        std::cout << "Catched out_of_range!" << "\n";
    }
    Delete(del);
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
}
std::shared_ptr<Array::ArrNode> Array::MinMax(bool max, bool x)
{
    std::shared_ptr<ArrNode> tmp = first_;
    int mm_number = 0;
    int iterator = 0;
    if (max) {
        if(x) {
            while(nullptr != tmp->right_) {
                ++iterator;
                if (tmp->x_ < tmp->right_->x_) {mm_number = iterator;}
                tmp = tmp->right_;
            }
        } else if (x == false) {           
            while(nullptr != tmp->right_) {
                ++iterator;
                if (tmp->y_ < tmp->right_->y_) {mm_number = iterator;}
                tmp = tmp->right_;
            }            
        } 
    } else if (max == false) {
        if(x) {
            while(nullptr != tmp->right_) {
                iterator++;
                if(tmp->x_ > tmp->right_->x_) {mm_number = iterator;}
                tmp = tmp->right_;
            }
        } else if (x == false) {
            while(nullptr != tmp->right_) {
                iterator++;
                if(tmp->y_ > tmp->right_->y_) {mm_number = iterator;}
                tmp = tmp->right_;
            }
        }
    }
    std::cout << Moving(mm_number)->x_ << " " << Moving(mm_number)->y_ << " ";
    return Moving(mm_number);
};

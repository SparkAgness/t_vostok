#ifndef CHANGE_ARR
#define CHANGE_ARR

#include <algorithm>

class Changeable_Array final
{
    private:
        int** coord_;//
	int lenght_;

    public:
        Changeable_Array(int, int); //OK
        Changeable_Array(const Changeable_Array& ); //OK
        Changeable_Array(Changeable_Array &&); //OK
        Changeable_Array& operator=(const Changeable_Array&); //OK
        Changeable_Array& operator=(Changeable_Array&&); //OK
        ~Changeable_Array() {delete *coord_;}; //OK

        int* CoordValues(int) const;//OK
        int** GetCoord() const; //OK
        int GetLenght() const; //OK
        void PushBack(int*); //OK
        void ChangeMember(int, int, bool); //OK
        int MinMax_Index(bool, bool);
};

int Changeable_Array::MinMax_Index(bool x_max, bool y_max)
//if x_max is true, method finds the max value of all 2-demensions array
//if y_max is false, method finds the min value of 2-demensions array's member with finding x-coordinate
//returns the number of 2-demensions array with defined terms of min/max
{
    int index = 0;
    int& ind = index;
    if (x_max) {
        for (int i = 1; i < lenght_; ++i) {
            if (*(*coord + i) > *(*coord + ind)) {ind = i;} 
	} 
    } else if (!x_max) {
        for (int i = 1; i < lenght_; ++i) {
            if (*(*coord + i) < *(*coord + ind)) {ind = i;}
        }
    }

    //to be continiued...
};

void Changeable_Array::ChangeMember(int mem_numb, int  value, bool second_column = 0
{
    if (second_column) {
        *(*(coord_ + mem_numb) + 1) = value;
    } else {
        *(*(coord_ + mem_numb)) = value;
    }
};

int* Changeable_Array::CoordValues(int row) const
{
    return *(this->coord_ + row);
};

void Changeable_Array::PushBack(int* push)
{

    this->lenght_ += 1;
    int** coord = new int*[this->lenght_];
    for (int i = 0; i < this->lenght_ - 1; ++i) {
        *(coord + i) = new int[2] {*(*(this->coord_ + i)), *(*(this->coord_ + i) + 1)};
    }
    *(coord + this->lenght_ - 1) = new int[2] {*(push), *(push + 1)};
    for (int i = 0; i < this->lenght_ - 1; ++i) {delete [] *(this->coord_ + i);}
    this->coord_ = coord;
    for (int i = 0; i < this->lenght_; ++i) {delete [] *(coord + i);}

};

int Changeable_Array::GetLenght() const
{
    return this->lenght_;
};

int** Changeable_Array::GetCoord() const
{
    return this->coord_;
};

Changeable_Array& Changeable_Array::operator=(Changeable_Array&& rhs)
{
    if (this != &rhs) {
        this->coord_ = rhs.coord_;
        this->lenght_ = rhs.lenght_;
        rhs.coord_ = nullptr;
        rhs.lenght_ = 0;
    }
    return *this;
};

Changeable_Array& Changeable_Array::operator=(const Changeable_Array& rhs)
{
    if (this != &rhs) {
        this->coord_ = rhs.coord_; //the coord_ is private will be it works?
	this->lenght_ = rhs.lenght_;
    }
    return *this;
};

Changeable_Array::Changeable_Array(int x, int y)
{
    this->lenght_ = 1;
    this->coord_ = new int*[this->lenght_];
    *(this->coord_) = new int[2] {x, y};
};

Changeable_Array::Changeable_Array(Changeable_Array&& source)
{
    lenght_ = source.lenght_;
    coord_ = new int*[lenght_];
    std::swap(source.coord_, coord_);
};


Changeable_Array::Changeable_Array(const Changeable_Array& source)
{
    this->lenght_ = source.lenght_;
    this->coord_ = new int*[this->lenght_];
    for (int i = 0; i < this->lenght_; ++i) {
        *(coord_ + i) = new int[2] {*(*(source.coord_ + i)), *(*(source.coord_ + i) + 1)};
    }
};
#endif


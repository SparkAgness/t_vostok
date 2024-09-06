#ifndef CHANGE_ARR
#define CHANGE_ARR

#include <algorithm>

class Changeable_Array final
{
    private:
        int** coord_;//
	int lenght_;
        int MinMax(bool, bool);//OK
        int** Coord_Array();
	//after using **Coord_Array it is necessary to delete pointer and free the heap!!!

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
        void Eraser(bool*);
};

int** Changeable_Array::Coord_Array()
//returns array(int**) of coordinates to be erased by method Eraser()
//array consists of coordinates: 0member - corner, 1member - left/right, 2member - up/down
{
    int** arr = new int* [3] {};
    for (int i = 0; i < 3; ++i) {*(arr + i) = new int [2];} 

};

void Changeable_Array::Eraser(bool* er_arr) 
//bool er_arr[5] {left_up, right_up, right_down, left_down, one_diagonal_row_erase}
{

};

int Changeable_Array::MinMax(bool coord_x, bool maxim)
//if coord_x is true, finds x, else - finds y
//if max is true, finds maximum, else - minimum
//returns set value of min/max of x/y
{
    int index = 0;
    int& ind = index;
    if (coord_x) {
        for (int i = 1; i < lenght_; ++i) {
            if (maxim) { 
                if (*(*(coord_ + i)) > *(*(coord_ + ind))) {ind = i;} 
            } else if (!maxim) {
                if (*(*(coord_ + i)) < *(*(coord_ + ind))) {ind = i;}
            }
        }
    } else if (!coord_x) {
        for (int i = 1; i < lenght_; ++i) {
            if (maxim) {
                if (*(*(coord_ + i) + 1) > *(*(coord_ + index) + 1)) {ind = i;}
	    } else if (!maxim) {
                if (*(*(coord_ + i) + 1) < *(*(coord_ + index) + 1)) {ind = i;}
            }
	}
    }
    return index;
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


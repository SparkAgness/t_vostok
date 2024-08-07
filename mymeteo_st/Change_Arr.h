#ifndef CHANGE_ARR
#define CHANGE_ARR

class Changeable_Array final
{
    private:
        int** coord_;
	int lenght_;

    public:
        Changeable_Array(int, int) = default; //OK
        Changeable_Array(const Changeable_Array& ); //OK
        Changeable_Array(Changeable_Array &&); //OK
        Changeable_Array& operator=(const Changeable_Array&); //OK
        Changeable_Array& operator=(Changeable_Array&&); //OK
        ~Changeable_Array() {delete *coord_}; //OK

        int* CoordValues(int, int);
        int** GetCoord() const; //OK
        int GetLength() const; //OK
        void PushBack(int*); //OK
};

int* Changeable_Array::CoordValues(int row)
{
    return *(this->coord + row);
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
    for (int i = 0; i < this->coord; ++i) {delete [] *(coord + i);}

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
    std::swap(source);
};


Changeable_Array::Changeable_Array(const Changeable_Array& source)
{
    this->lenght_ = source.lenght_();
    this->coord_ = new int*[this->lenght];
    for (int i = 0; i < this->lenght; ++i) {
        *(*(this->lenght) + i) = new int[2] {*(*(source.coord_ + i)), *(*(source.coord_ + i) + 1)};
    }
};
#endif


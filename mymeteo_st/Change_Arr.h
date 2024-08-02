#ifndef CHANGE_ARR
#define CHANGE_ARR

class Changeable_Array
{
    private:
        int** coord_;
	int lenght_;

    public:
        Changeable_Array(int, int) = default; //OK
        Changeable_Array(const Changeable_Array& ); //OK
        Changeable_Array& operator=(const Chageable_Array&);
        ~Changeable_Array() {delete *coord_};
        int** GetCoord() const;
        int GetLength() const;
};

int Changeable_Array::GetLenght() const
{
    return this->lenght_;
};

int** Changeable_Array::GetCoord() const
{
    return this->coord_;
};

Changeable_Array::Changeable_Array(int x, int y)
{
    int* coord = new int [2];
    *coord = x;
    *(coord + 1) = y;
    *(this->coord_) = coord;
    this->lenght_ = 1;
};

Changeable_Array::Changeable_Array(const Changeable_Array& source)
{
    this->lenght_ = source.GetLenght();
    this->coord_ = new int[2*this->lenght];
    for (int i = 0; i < this->lenght; ++i) {
        *(*(this->lenght + i)) = *(*(source.GetCoord + i));
        *(*(this->lenght + i) + 1) = *(*(source.GetCoord + i) + 1);
    }
};
#endif


#define FIELD_SIZE 27

Symbol_Writer(int s)
{
    private:
        int s_;
        int x_ [FIELD_SIZE];
        int y_ [FIELD_SIZE];
	int xy_ [][2];

    public:
        Symbol_Writer();
	void Symbol_Creater(int);
}

Symbol_Writer::Symbol_Writer(int s) : s_(s)
{
    for (int i = 0; y < FIELD_SIZE; ++y) {
        *(this->x + i) = i;
        *(this->y + i) = i;
    }
};


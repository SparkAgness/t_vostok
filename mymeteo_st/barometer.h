#ifndef BARO
#define BARO

#define PRES_MONIT 24

class Barometer
{
    private:
        int pres[2]; //each 10 minutes 
        int rain_possible[PRES_MONIT];
        int storm_possible[PRES_MONIT]; 
        int pres_dif_pointer;
        class BaroCounter { //is needs for remaking - press is not necessary, debug the int possible iteration
            private:
                int press; //to make it private!
                int possible;//to make it private!
            public:
                int GetIndPress() const;
                int GetIndPossible() const;
                BaroCounter();
                BaroCounter& operator ++ ();
        };
        BaroCounter count;

    public:
        Barometer(); //OK
        void PushPress(int); //OK
        void PushRain(int);
        const int GetDiffPress();
        void PressDifPointerSw();
        void 
};

void Barometer::PressDifPointerSw()
{
    if (!(*(this->pres)) && !(*(this->pres + 1))) {this->pres_dif_pointer = 0;}
    else if (*(this->pres) && !(*(this->pres + 1))) {this->pres_dif_pointer = 1;}
    else if (*(this->pres) && *(this->pres + 1) && (this->pres_dif_pointer = 1)) {this->pres_dif_pointer = 0;}
    else if (*(this->pres) && *(this->pres + 1) && (this->pres_dif_pointer = 0)) {this->pres_dif_pointer = 1;};
};

const int Barometer::GetDiffPress()
{
    return *(this->pres + this->count.GetIndPossible()) - *(this->pres + this->count.GetIndPossible() - 1); //press is private!!!
};

void Barometer::PushRain(int val)
{
    *(this->rain_possible + this->count.GetIndPossible()) = *(this->pres + this->count.GetIndPress()) - *(this->pres + this->count.GetIndPress() - 1);
};

void Barometer::PushPress(int val)
{
    *(this->pres + this->press_dif_pointer) = val;
};

int Barometer::BaroCounter::GetIndPress() const
{
    return this->press;    
};

int Barometer::BaroCounter::GetIndPossible() const
{
    return this->possible;
};

Barometer::BaroCounter& Barometer::BaroCounter::operator ++()
{
    this->press = this->press + 1;
    if (PRES_MONIT == this->press) {this->press = 0;}
    if (!this->press) {this->possible = 0;}
    else {this->possible = this->press - 1;}
    return *this; 
};

Barometer::BaroCounter::BaroCounter()
{
    this->press = 0;
    this->possible = 0;
};

Barometer::Barometer()
{
    for (int i = 0; i < PRES_MONIT; ++i) {
        *(this->rain_possible + i) = 0;
        *(this->storm_possible + i) = 0;
    }
    *(this->pres) = 0;
    *(this->pres + 1) = 0;
    pres_dif_pointer = 0;
};
#endif

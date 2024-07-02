#ifndef BARO
#define BARO

#define PRES_MONIT 24

class Barometer
{
    private:
        int pres[2]; //each 10 minutes 
        int rain_possible[PRES_MONIT];
        int storm_possible[PRES_MONIT]; 
        int pres_dif_pointer; //points to next arr's space to place next int pres value
        int help_counter;        
    public:
        Barometer(); //OK
        void PushPress(int); //OK
        void PushRain(int);
        const int GetDiffPress(); //OK
        void PressDifPointerSw(); //OK
         
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
    if (!pres_dif_pointer) {return (*(this->pres) - *(this->pres + 1)); }
    return (*(this->pres + 1) - *(this->pres));
};

void Barometer::PushRain(int val)
{
    *(this->rain_possible + this->count.GetIndPossible()) = *(this->pres + this->count.GetIndPress()) - *(this->pres + this->count.GetIndPress() - 1);
};

void Barometer::PushPress(int val)
{
    *(this->pres + this->press_dif_pointer) = val;
};


Barometer::Barometer()
{
    this->pres_dif_pointer = 0;
    this->help_counter = 0;
    for (int i = 0; i < PRES_MONIT; ++i) {
        *(this->rain_possible + i) = 0;
        *(this->storm_possible + i) = 0;
    }
    *(this->pres) = 0;
    *(this->pres + 1) = 0;
};
#endif

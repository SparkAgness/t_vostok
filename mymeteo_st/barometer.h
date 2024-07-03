#ifndef BARO
#define BARO

#define PRES_MONIT 24
#define DIF_RAIN 2 //for paste to rain_possible[]
#define DIF_STORM 4 //for paste to storm_possible[]

class Barometer
{
    private:
        int pres[2]; //each 10 minutes 
        int rain_possible[PRES_MONIT];
        int pres_dif_pointer; //points to next arr's space to place next int pres value
        int push_pointer; //points to paste's place into rain_possible 
        int prediction_factor; //base to int Prediction(). It is a sum/div all difference values from int pres[]
    public:
        Barometer(); //OK
        void PushPress(int); //OK
        void PushDiff(); //OK
        int GetDiffPress() const; //OK
        void PressDifPointerSw(); //OK
        void IncrPushPointer(); //OK
        void DecrPushPointer();
        int GetPushPointer() const; //OK
        int Prediction() const;
         
};

int Barometer::Prediction() const
{

};

int Barometer::GetPushPointer() const
{
    return this->push_pointer;
};

void Barometer::DecrPushPointer()
{
    this->push_pointer -= 1;
    if (this->push_pointer < 0) {this->push_pointer = PRES_MONIT - 1;}
};

void Barometer::IncrPushPointer()
{
    this->push_pointer += 1;
    if (PRES_MONIT <= this->push_pointer) {this->push_pointer = 0;}
};

void Barometer::PushDiff()
{
    *(this->rain_possible + this->GetPushPointer()) = this->GetDiffPress();
};

void Barometer::PressDifPointerSw()
{
    if (!(*(this->pres)) && !(*(this->pres + 1))) {this->pres_dif_pointer = 0;}
    else if (*(this->pres) && !(*(this->pres + 1))) {this->pres_dif_pointer = 1;}
    else if (*(this->pres) && *(this->pres + 1) && (this->pres_dif_pointer = 1)) {this->pres_dif_pointer = 0;}
    else if (*(this->pres) && *(this->pres + 1) && (this->pres_dif_pointer = 0)) {this->pres_dif_pointer = 1;};
};

int Barometer::GetDiffPress() const
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
    this->prediction_factor = 0;
    for (int i = 0; i < PRES_MONIT; ++i) {
        *(this->rain_possible + i) = 0;
    }
    *(this->pres) = 0;
    *(this->pres + 1) = 0;
};
#endif

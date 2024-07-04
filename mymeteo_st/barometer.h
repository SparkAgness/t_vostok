#ifndef BARO
#define BARO

#define PRES_MONIT 24
#define RAIN_P 2 //for paste to rain_possible[]
#define STORM_P 4 //for paste to storm_possible[]

class Barometer
{
    private:
        int pres[2]; //each 10 minutes 
        int samples; //counter of paste's rain_possible 
        int barometer_dif;
        int prediction_factor; //base to int Prediction(). It is a sum/div all difference values from int pres[]
    public:
        Barometer(); //OK
        void SetSamples(); //OK
        int GetSamples() const; //OK
        void SetBarDiff(int); //OK
        int GetBarDiff() const; //OK
        int GetPrediction();                 
        void PressPush(int);
	
};

void Barometer::PressPush(int val)
{
    if (!*(this->pres)) {*(this->pres) = val;}
    else if (*(this->pres) && (!*(this->pres + 1))) {*(this->pres + 1) = val;}
    else {*(this->pres) = *(this->pres + 1); *(this->pres + 1) = val;}
};

int Barometer::GetBarDiff() const
{
    return this->barometer_dif;
};

void Barometer::SetBarDiff(int value)
{
    if (!this->samples) {this->barometer_dif = 0;}
    int dif = *(this->pres + 1) - *(this->pres);
    this->barometer_dif += dif;
}

int Barometer::GetSamples() const
{
    return this->samples;
};

void Barometer::SetSamples
{
    this->samples += 1;
    if (PRES_MONIT == this->samples) {this->samples = 0;}
};

Barometer::Barometer()
{
    this->samples = 0;
    this->barometer = 0;
    this->prediction_factor = 0;
    for (int i = 0; i < 22; ++i) {
        *(this->pres + i) = 0;
    }
};
#endif

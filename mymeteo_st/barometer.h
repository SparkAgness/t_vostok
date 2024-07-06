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
        double prediction_factor; //base to int Prediction(). It is a sum/div all difference values from int pres[]
        bool start;
        bool get_out_data;
        int rain_prediction;
    public:
        Barometer(); //OK
        void SetSamples(); //OK
        int GetSamples() const; //OK
        void SetBarDiff(); //OK
        int GetBarDiff() const; //OK
        void GetPrediction();                 
        void PressPush(int, int); //OK
        void SetRainPrediction();
        int GetRainPrediction() const;
};

int Barometer::GetRainPrediction() const
{
    return this->rain_prediction;
};

void Barometer::SetRainPrediction()
{
    if ((-1)*this->samples <= this->prediction_factor < 0) {this->rain_prediction = 50;}
    else if ((-2)*this->samples <= this->prediction_factor < (-1)*this->samples) {this->rain_prediction = 85;}
    else {this->rain_prediction = 10;}
};

void Barometer::GetPrediction()
{
    if (!this->samples) {this->prediction_factor = 0;}
    else {this->prediction_factor = (double)this->barometer_dif/(double)this->samples;}
};


void Barometer::PressPush(int val, int minutes) //Always pres[1] is later than pres[0]
{
    if (15 != minutes || 30 != minutes || 45 != minutes || 0 != minutes) {this->get_out_data = true;}
    else if ((this->get_out_data) && (15 == minutes || 30 == minutes || 45 == minutes || 0 == minutes)) {
        if (!this->start) {*(this->pres) = val; *(this->pres + 1) = val; this->start = true;}
        else {*(this->pres) = *(this->pres + 1); *(this->pres + 1) = val;}
        this->SetBarDiff();
        this->SetSamples();
        this->get_out_data = false;
    }
};

int Barometer::GetBarDiff() const
{
    return this->barometer_dif;
};

void Barometer::SetBarDiff()
{
    if (!this->samples) {this->barometer_dif = 0;}
    int dif = *(this->pres + 1) - *(this->pres);
    this->barometer_dif += dif;
}

int Barometer::GetSamples() const
{
    return this->samples;
};

void Barometer::SetSamples()
{
    this->samples += 1;
    if (PRES_MONIT == this->samples) {this->samples = 0;}
};

Barometer::Barometer()
{
    this->start = false;
    this->get_out_data = false;
    this->samples = 0;
    this->barometer_dif = 0;
    this->prediction_factor = 0;
    this->rain_prediction = 0;
    for (int i = 0; i < 22; ++i) {
        *(this->pres + i) = 0;
    }
};
#endif

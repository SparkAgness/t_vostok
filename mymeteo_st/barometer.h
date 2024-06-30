#ifndef BARO
#define BARO

#define PRES_MONIT 24
#define CALC_PROB 8 

class Barometer
{
    private:
        int pres[PRES_MONIT]; //each 10 minutes 
        int rain_possible[CALC_PROB]; //each 30 minutes
        int storm_possible[CALC_PROB]; //each 30 minutes
        class BaroCounter {
            int press;
            int possible;
		            public:
            BaroCounter();
            BaroCounter& operator ++ ();
        };
    public:
        Barometer(); //OK
        void PushPress(int);
};

void Barometer::PushPress(int val)
{

};

Barometer::BaroCounter& Barometer::BaroCounter::operator ++()
{
    this->press = this->press + 1;
    if (1 == this->press%CALC_PROB) {this->possible = this->possible + 1;}
    if (PRES_MONIT == this->press) {this->press = 0;}
    if (CALC_PROB == this->possible) {this->possible = 0;}
    return *this; 
};

Barometer::BaroCounter::BaroCounter()
{
    this->press = 0;
    this->possible = 0;
};

Barometer::Barometer()
{
    for (int i = 0; i < CALC_PROB; ++i) {
        *(this->pres + i) = 0;
        *(this->rain_possible + i) = 0;
	*(this->storm_possible + i) = 0;
    }
    for (int i = CALC_PROB; i < PRES_MONIT; ++i) {
        *(this->pres + i) = 0;
    }
    BaroCounter count;
};
#endif

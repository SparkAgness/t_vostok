#ifndef BARO
#define BARO

#define PRES_MONIT 24
#define CALC_PROB 8 

class Barometer
{
    private:
        int pres[PRES_MONIT]; //each 10 minutes 
        int rain_possible[PRES_MONIT - 1];
        int storm_possible[PRES_MONIT - 1]; 
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
    *(this->pres + this->count.press) = val;
};

Barometer::BaroCounter& Barometer::BaroCounter::operator ++()
{
    this->press = this->press + 1;
     
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

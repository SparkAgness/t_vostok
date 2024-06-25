#ifndef STAT
#define STAT

#define HOURS 12
#define STAT_DAYS 10

class Statistic
{
    private:
        int day_hours[12];
        int night_hours[12];
        int av_day_temp[10];
        int av_night_temp[10];
        int empty_field; //the var-counter for day/night hours arrays
        int next_av_field; //the var-counter for av_day/av_night temp arrays

    public:
	Statistic();
        void SetHours(int hours); //filling corresponding day/night hours values (OK)
        void SetEmptyField(int* arr); //sets this->empty_field next after field's non-zero value of count - only for day/night hours (OK)
        void SetNextAvField(); //sets the counter for filling field for av_day/av_night arrays (OK)
        void ClearFullArr(int* arr); //clears full array - only for day/night_hours
        int AvTemp(int* arr_s, int* arr_d); //calculates the values of average temp for av_day/av_night
        void SetAvTemp(int* arr); //filling correspondings av_day/av_night temperature's values
};

void Statistic::SetNextAvField() 
{
    this->next_av_field += 1;
    if (STAT_DAYS == this->next_av_field) {this->next_av_field = 0;}
};

void Statistic::SetEmptyField(int* arr) 
{
    for (int i = 0; i < HOURS; ++i) {
        if (!*(arr + i)) this->empty_field = i;
    }
};

void Statistic::SetHours(int hours)
{
    int i = 0;
    if (hours > 8 && hours < 21) {
        i = hours - 9;
        this->*(day_hours + i) = hours;
    } else if (hours > 20) {
        i = hours - 12;
        this->*(night_hours + i) = hours;
    } else {
        i = hours;
        this->*(night_hours + i) = hours;
    }
};

Statistic::Statistic()
{
    this->next_av_field = 0;
    this->empty_field = 0;
    for (int i = 0; i < HOURS; ++i) {
        this->day_hours[i] = 0;
        this->night_hours[i] = 0;
    }
    for (int i = 0; i < STAT_DAYS; ++i) {
        this->av_day_temp[i] = 0;
        this->av_night_temp[i] = 0;
    } 
};
#endif

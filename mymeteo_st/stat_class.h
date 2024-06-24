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
        int empty_field;

    public:
	Statistic();
        void SetHours(int hours);
        void SetEmptyField();
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
    empty_field = 0;
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

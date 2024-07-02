#ifndef STAT
#define STAT

#define HOURS 12
#define STAT_DAYS 10 

class Statistic
{
    private:
        int day_hours[HOURS];
        int night_hours[HOURS];
        int day_humid[2*HOURS];
        int av_day_temp[STAT_DAYS];
        int av_night_temp[STAT_DAYS];
        int av_humid[STAT_DAYS];
        int empty_field; //the var-counter for day/night hours arrays
        int next_av_field; //the var-counter for av_day/av_night temp arrays
        bool filling_en;

    public:
	Statistic();
        void SetHours(int hours, int hours_val); //filling corresponding day/night hours values (OK)
        void SetEmptyField(int* arr); //sets this->empty_field next after field's non-zero value of count - only for day/night hours (OK)
        void SetNextAvField(); //sets the counter for filling field for av_day/av_night arrays (OK)
        void ClearFullArr(); //clears full array - only for day/night_hours (OK)
        int AvTemp(bool day = true); //calculates the values of average temp for av_day/av_night (OK)
        void SetAvTemp(); //filling correspondings av_day/av_night temperature's values (OK)
        void SetAvHumid();
        void SetHumidity(int hours, int val);
        const int GetDayAverage(int days_ago = 1); //by default is yesterday
        const int GetNightAverage(int days_ago = 1); //by default is yesterday
        const int GetHumidAverage(int days_ago = 1); //by default is yesterday
        void SwitchFillingEn(bool);
};

void Statistic::SetHumidity(int hours, int val)
{
    if (this->filling_en) {*(this->day_humid + hours) = val;}
};

void Statistic::SwitchFillingEn(bool flag)
{
    if (!flag) {this->filling_en = false;}
    if (flag) {this->filling_en = true;}
};

const int Statistic::GetHumidAverage(int days_ago)
{
    return *(this->av_humid + this->next_av_field - days_ago);
};

void Statistic::SetAvHumid()
{
    int sum = 0;
    for (int i = 0; i < 2*HOURS; ++i) {
        sum += *(this->day_humid + i);
    } 
    sum /= 2*HOURS;
    if (this->filling_en) {*(this->av_humid + next_av_field) = sum;}
};

const int Statistic::GetDayAverage(int days_ago)
{
    return *(this->av_day_temp + this->next_av_field - days_ago);
};

const int Statistic::GetNightAverage(int days_ago)
{
    return *(this->av_night_temp + this->next_av_field - days_ago);
};

void Statistic::SetAvTemp()
{
    if (this->filling_en) {
        *(this->av_night_temp + this->next_av_field) = this->AvTemp(false);
        *(this->av_day_temp + this->next_av_field) = this->AvTemp();
    }
};

int Statistic::AvTemp(bool day)
{
    int sum = 0;
    for (int i = 0; i < HOURS; ++i) {
        if (day) {
            sum += *(this->day_hours + i);
        } else {
            sum += *(this->night_hours + i);
        }
    }
    sum /= HOURS;
    return sum;
};


void Statistic::ClearFullArr()
{
    if (this->filling_en) {
        for (int i = 0; i < HOURS; ++i) {
            *(this->day_hours + i) = 0;
            *(this->night_hours + i) = 0;
            *(this->day_humid + i) = 0;
        }
        for (int i = HOURS; i < 2*HOURS; ++i) {*(this->day_humid + i) = 0;}
    }
};

void Statistic::SetNextAvField() 
{
    if (this->filling_en) {
        this->next_av_field += 1;
        if (STAT_DAYS == this->next_av_field) {this->next_av_field = 0;}
    }
};

void Statistic::SetEmptyField(int* arr) 
{
    for (int i = 0; i < HOURS; ++i) {
        if (!*(arr + i)) this->empty_field = i;
    }
};

//to test it
void Statistic::SetHours(int hours, int hours_val)
{
    if (this->filling_en) {
        int i = 0;
        if (hours > 8 && hours < 21) {
            i = hours - 9;
            this->day_hours[i] = hours_val;
        } else if (hours > 20) {
            i = hours - 12;
            this->night_hours[i] = hours_val;
        } else {
            i = hours;
            this->night_hours[i] = hours_val;
        }
    }
};

Statistic::Statistic()
{
    this->next_av_field = 0;
    this->filling_en = true;
    this->empty_field = 0;
    for (int i = 0; i < HOURS; ++i) {
        this->day_hours[i] = 0;
        this->night_hours[i] = 0;
    }
    for (int i = 0; i < STAT_DAYS; ++i) {
        this->av_day_temp[i] = 0;
        this->av_night_temp[i] = 0;
        this->av_humid[i] = 0;
    } 
    for (int i = 0; i < 2*HOURS; ++i) {
        this->day_humid[i] = 0;
    }
};
#endif

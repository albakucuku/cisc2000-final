//header files
#include "timer.h"

#include <iostream>
#include <sstream>

using namespace std;

Timer::Timer()
{
    hours = 0;
    minutes = 0;
    seconds = 0;
}
// Define a constructer 
//includes param h, m and s
Timer::Timer(int h, int m, int s)
{
    hours = h;
    minutes = m;
    seconds = s;
}
//define get value function 
int Timer::get_value() const
{
    //function return 
    return hours * 3600 + minutes * 60 + seconds;
}

void Timer::set_value(int value)
{
    hours = value / 3600;
    value %= 3600;
    minutes = value / 60;
    seconds = value % 60;
}

int Timer::increment(int amount)
{
    set_value(get_value() + amount);
    return get_value();
}

int Timer::decrement(int amount)
{
    int value = get_value() - amount;
    if (value < 0) 
        value = 0;
    set_value(value);
    return get_value();
}

string Timer::as_string() const
{
    stringstream ss;
    ss << hours << ":" << minutes << ":" << seconds;
    return ss.str();
}

Timer operator+(const Timer& t, int amount)
{
    Timer result(t);
    result.increment(amount);
    return result;
}

Timer operator-(const Timer& t, int amount)
{
    Timer result(t);
    result.decrement(amount);
    return result;
}

istream& operator>>(istream& ins, Timer& timer)
{
    char delimiter;
    ins >> timer.hours >> delimiter >> timer.minutes >> delimiter >> timer.seconds;
    if (ins.fail())
        ins.setstate(ios::failbit);
    return ins;
}

ostream& operator<<(ostream& outs, const Timer& timer)
{
    outs << timer.as_string();
    return outs;
}

bool Timer::operator==(const Timer& t) const
{
    return get_value() == t.get_value();
}

bool Timer::operator!=(const Timer& t) const
{
    return !(*this == t);
}

bool Timer::operator<(const Timer& t) const
{
    return get_value() < t.get_value();
}

bool Timer::operator>(const Timer& t) const
{
    return get_value() > t.get_value();
}

int Timer::get_hours() const
{
    return hours;
}

int Timer::get_minutes() const
{
    return minutes;
}

int Timer::get_seconds() const
{
    return seconds;
}

Timer& Timer::operator++()
{
    increment(1);
    return *this;
}

Timer& Timer::operator--()
{
    decrement(1);
    return *this;
}

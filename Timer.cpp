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

Timer::Timer(int h, int m, int s)
{
    hours = h;
    minutes = m;
    seconds = s;
}

int Timer::get_value() const
{
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

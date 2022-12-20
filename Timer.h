#ifndef TIMER_H
#define TIMER_H

#include "measurement.h"

class Timer : public Measurement
{
  private:
    int hours, minutes, seconds;

  public:
    Timer();
    Timer(int h, int m, int s);
    int get_value() const;
    void set_value(int value);
    int increment(int amount);
    int decrement(int amount);
    string as_string() const;
    friend Timer operator+(const Timer& t, int amount);
    friend Timer operator-(const Timer& t, int amount);
    friend istream& operator>>(istream& ins, Timer& timer);
    friend ostream& operator<<(ostream& outs, const Timer& timer);
    bool operator==(const Timer& t) const;
    bool operator!=(const Timer& t) const;
    bool operator<(const Timer& t) const;
    bool operator>(const Timer& t) const;
    int get_hours() const;
    int get_minutes() const;
    int get_seconds() const;
    Timer& operator++();
    Timer& operator--();
};

#endif

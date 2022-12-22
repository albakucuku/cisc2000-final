#ifndef TIMER_H
#define TIMER_H
//header files
#include "measurement.h"

class Timer : public Measurement
{
  //create variables hours, minutes, seconds
  private:
    int hours, minutes, seconds;

  public:
    //declaration of default constructor 
    // and constructor with with param h,m and s
    Timer();
    Timer(int h, int m, int s);
    //function declaration get_value constant 
    //set value with @param value
    //increment and decrement with varaibles amount
    int get_value() const;
    void set_value(int value);
    int increment(int amount);
    int decrement(int amount);
    string as_string() const;
    //funtions that reads in and writes out the time object
    friend Timer operator+(const Timer& t, int amount);
    friend Timer operator-(const Timer& t, int amount);
    friend istream& operator>>(istream& ins, Timer& timer);
    friend ostream& operator<<(ostream& outs, const Timer& timer);
    //operator overload for the ==, !=, <, > operator that compares 
    bool operator==(const Timer& t) const;
    bool operator!=(const Timer& t) const;
    bool operator<(const Timer& t) const;
    bool operator>(const Timer& t) const;
    //declaration of get_hour, get_minutes, get_seconds function
    int get_hours() const;
    int get_minutes() const;
    int get_seconds() const;
    Timer& operator++();
    Timer& operator--();
};

#endif

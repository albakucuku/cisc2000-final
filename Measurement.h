#ifndef MEASUREMENT_H
#define MEASUREMENT_H

#include <string>

using namespace std;

class Measurement
{
  public:
    virtual int get_value() const = 0;
    virtual void set_value(int value) = 0;
    virtual int increment(int amount) = 0;
    virtual int decrement(int amount) = 0;
    virtual string as_string() const = 0;
    virtual int compare(const Measurement& measure) { return get_value() - measure.get_value(); };
};

#endif

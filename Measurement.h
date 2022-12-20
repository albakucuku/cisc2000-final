#ifndef MEASUREMENT_H
#define MEASUREMENT_H

#include <string>

using namespace std;

class Measurement
{
  public:
    virtual int get_value() const = 0;
   // returns Measurement in terms of the smallest unit
   // Use this function to compare, increment and decrement.
    virtual void set_value(int value) = 0;
   // A function that sets the Measurement to the given value
    virtual int increment(int amount) = 0;
   // increments the value by a given amount, returns changed value
    virtual int decrement(int amount) = 0;
   // decreases the value by amount but does not let it go negative
    virtual string as_string() const = 0;
   // A function that creates a string representing the Measurement. 
   // It should have a specific number of digits per part: mm/dd/yyyy
   // for date
    virtual int compare(const Measurement& measure) { return get_value() - measure.get_value(); };
   // returns > 0 if invoking object is greater than measure
   // return 0 if they are equal
};
  

#endif

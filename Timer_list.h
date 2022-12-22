#ifndef TIMER_LIST_H
#define TIMER_LIST_H
//header files
#include "timer.h"
//class TimerList
class TimerList
{
  private:
  //variables size and capacity
  //pointer to a pointer 
    Timer** list;
    int size;
    int capacity;

  public:
  //declaration of default constructor
  //declaration of constructir with @param capacity
    TimerList();
    TimerList(int capacity);
  //declaration of destructor
    ~TimerList();
  //decarations for functions add,and remove
    void add(const Timer& timer);
    void remove(int index);
  //clear function
    void clear();
  //constant function to get size and capacity
    int get_size() const;
    int get_capacity() const;
  //declare overloading[] operator
    Timer& operator[](int index);
    const Timer& operator[](int index) const;
};

#endif

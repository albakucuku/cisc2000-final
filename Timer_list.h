#ifndef TIMER_LIST_H
#define TIMER_LIST_H

#include "timer.h"

class TimerList
{
  private:
    Timer** list;
    int size;
    int capacity;

  public:
    TimerList();
    TimerList(int capacity);
    ~TimerList();
    void add(const Timer& timer);
    void remove(int index);
    void clear();
    int get_size() const;
    int get_capacity() const;
    Timer& operator[](int index);
    const Timer& operator[](int index) const;
};

#endif

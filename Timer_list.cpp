#include "timer_list.h"

#include <iostream>

using namespace std;

TimerList::TimerList()
{
    list = new Timer*[10];
    size = 0;
    capacity = 10;
}

TimerList::TimerList(int capacity)
{
    list = new Timer*[capacity];
    size = 0;
    this->capacity = capacity;
}

TimerList::~TimerList()
{
    clear();
    delete[] list;
}

void TimerList::add(const Timer& timer)
{
    if (size == capacity)
    {
        capacity *= 2;
        Timer** new_list = new Timer*[capacity];
        for (int i = 0; i < size; i++)
            new_list[i] = list[i];
        delete[] list;
        list = new_list;
    }
    list[size] = new Timer(timer);
    size++;
}

void TimerList::remove(int index)
{
    delete list[index];
    for (int i = index; i < size - 1; i++)
        list[i] = list[i + 1];
    size--;
}

void TimerList::clear()
{
    for (int i = 0; i < size; i++)
        delete list[i];
    size = 0;
}

int TimerList::get_size() const
{
    return size;
}

int TimerList::get_capacity() const
{
    return capacity;
}

Timer& TimerList::operator[](int index)
{
    return *list[index];
}

const Timer& TimerList::operator[](int index) const
{
    return *list[index];
}

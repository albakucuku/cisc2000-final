#include "timer_list.h"
//header
#include <iostream>

using namespace std;
//define a constructor
TimerList::TimerList()
{
    list = new Timer*[10];
    size = 0;
    capacity = 10;
}
//define a constructor with capacity
TimerList::TimerList(int capacity)
{
    list = new Timer*[capacity];
    size = 0;
    this->capacity = capacity;
}
//detructor that deletes the list of array
TimerList::~TimerList()
{
    clear();
    delete[] list;
}
//function add has parameter timer
void TimerList::add(const Timer& timer)
{
    //checks if size equals capacity
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
//removes list and replace it by decrementing it
void TimerList::remove(int index)
{
    delete list[index];
    for (int i = index; i < size - 1; i++)
        list[i] = list[i + 1];
    size--;
}
//clears list and sets size to 0
void TimerList::clear()
{
    for (int i = 0; i < size;i++)
        delete list[i];
    size = 0;
}
//get_size returns size
int TimerList::get_size() const
{
    return size;
}
//get_capacity returns capacity
int TimerList::get_capacity() const
{
    return capacity;
}
//Implements operator [] that returns list index
Timer& TimerList::operator[](int index)
{
    return *list[index];
}
//Implements a constant operator [] that returns list index
const Timer& TimerList::operator[](int index) const
{
    return *list[index];
}

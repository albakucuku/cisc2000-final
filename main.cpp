#include "timer_list.h"
#include "timer.h"

#include <fstream>

using namespace std;

int main()
{
    TimerList timers;
    ifstream infile("test_data.txt");
    Timer timer;
    while (infile >> timer)
        timers.add(timer);
    infile.close();

    for (int i = 0; i < timers.get_size(); i++)
        cout << timers[i] << endl;

    return 0;
}

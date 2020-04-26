#include "CountDown.h"

CountDown::CountDown(int n) : countDown(n)
{
}

void CountDown::callback()
{
    this->countDown--;
    if (countDown == 0)
    {
        stop();
    }
    else
    {
        cout << countDown << "\n";
    }
}

void CountDown::start()
{
    PeriodicTimer::start(1000);
}

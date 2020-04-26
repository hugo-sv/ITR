#include "CountDown.h"
namespace td3
{

CountDown::CountDown(int n) : countDown(n)
{
}

void CountDown::callback()
{
    this->countDown--;
    cout << countDown << "\n";
    if (countDown == 0)
    {
        stop();
    }
}

void CountDown::start()
{
    PeriodicTimer::start(1000);
}

}
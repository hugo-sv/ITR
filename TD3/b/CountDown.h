#ifndef CountDown_h_INCLUDED
#define CountDown_h_INCLUDED
#include "PeriodicTimer.h"
#include "Timer.h"
using namespace std;

class CountDown : public PeriodicTimer
{
private:
    int countDown;

public:
    CountDown(int n);
    void callback();
    void start();
};
#endif
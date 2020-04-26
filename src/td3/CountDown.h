#ifndef td3_CountDown_h_INCLUDED
#define td3_CountDown_h_INCLUDED
#include "PeriodicTimer.h"
#include "Timer.h"
using namespace std;

namespace td3
{
class CountDown : public PeriodicTimer
{
private:
    int countDown;

public:
    CountDown(int n);
    void callback();
    void start();
};

}

#endif
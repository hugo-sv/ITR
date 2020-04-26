#ifndef td3_PeriodicTimer_h_INCLUDED
#define td3_PeriodicTimer_h_INCLUDED
#include "Timer.h"
using namespace std;

namespace td3
{

class PeriodicTimer : public Timer
{
public:
    PeriodicTimer();
    void start(double duration_ms);
    virtual void callback() = 0;
};

}
#endif
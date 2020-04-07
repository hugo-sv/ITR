#ifndef PeriodicTimer_h_INCLUDED
#define PeriodicTimer_h_INCLUDED
#include "Timer.h"
using namespace std;

class PeriodicTimer : public Timer
{
public:
    PeriodicTimer();
    void start(double duration_ms);
    virtual void callback() = 0;
};
#endif
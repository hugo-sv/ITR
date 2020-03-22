#ifndef PerioricTimer_h_INCLUDED
#define PerioricTimer_h_INCLUDED
#include "timer.h"
using namespace std;

class PeriodicTimer : public Timer
{
public:
    PeriodicTimer();
    void start(double duration_ms);
    virtual void callback() = 0;
};
#endif
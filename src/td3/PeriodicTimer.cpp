#include "PeriodicTimer.h"
namespace td3
{

PeriodicTimer::PeriodicTimer() : Timer() {}

void PeriodicTimer::start(double duration_ms)
{
    itimerspec its;
    its.it_value = timespec_from_ms(duration_ms);
    its.it_interval = timespec_from_ms(duration_ms);
    timer_settime(this->tid, 0, &its, nullptr);
}

}
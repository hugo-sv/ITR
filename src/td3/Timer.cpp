#include "Timer.h"
namespace td3
{

Timer::Timer()
{
    struct sigaction sa;
    sa.sa_flags = SA_SIGINFO;
    sa.sa_sigaction = call_callback;
    sigemptyset(&sa.sa_mask);
    sigaction(SIGRTMIN, &sa, nullptr);

    struct sigevent sev;
    sev.sigev_notify = SIGEV_SIGNAL;
    sev.sigev_signo = SIGRTMIN;
    // Data to be transmitted to the handler
    sev.sigev_value.sival_ptr = (void *)this;

    timer_create(CLOCK_REALTIME, &sev, &tid);
}

Timer::~Timer()
{
    timer_delete(tid);
}

void Timer::start(double duration_ms)
{
    itimerspec its;
    its.it_value = timespec_from_ms(duration_ms);
    timer_settime(tid, 0, &its, nullptr);
}


void Timer::stop()
{
    itimerspec its;
    its.it_value = timespec_from_ms(0);
    its.it_interval = timespec_from_ms(0);
    timer_settime(tid, 0, &its, nullptr);
}

void Timer::call_callback(int, siginfo_t *si, void *)
{
    static Timer* t = (Timer *)si->si_value.sival_ptr;
    t->callback();
}

}
#include "td1/posixHelpers.h"
#include <signal.h>
using namespace std;

timer_t timer(void (*myHandler)(int, siginfo_t *, void *), timespec value, timespec interval, void *data)
{
    struct sigaction sa;
    sa.sa_flags = SA_SIGINFO;
    sa.sa_sigaction = myHandler;
    sigemptyset(&sa.sa_mask);
    sigaction(SIGRTMIN, &sa, nullptr);
    // --
    struct sigevent sev;
    sev.sigev_notify = SIGEV_SIGNAL;
    sev.sigev_signo = SIGRTMIN;
    // Data to be transmitted to the handler
    sev.sigev_value.sival_ptr = data;
    // --
    timer_t tid;
    timer_create(CLOCK_REALTIME, &sev, &tid);
    itimerspec its;
    its.it_value = value;
    its.it_interval = interval;
    timer_settime(tid, 0, &its, nullptr);
    // The timer must be deleted with timer_delete(tid);
    return tid;
}
#include <iostream>
#include <string>
#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include <math.h>
#include <unistd.h>
#include <signal.h>
#include <time.h>
#include <errno.h>
using namespace std;

static const long ns_PER_s = 1000000000;
// static const long us_PER_s = 1000000;
static const long ms_PER_s = 1000;
static const long ns_PER_ms = ns_PER_s / ms_PER_s;

void handler1(int sig, siginfo_t *si, void *)
{
    std::cout << *(volatile int *)(si->si_value.sival_ptr) << std::endl;
    *(volatile int *)(si->si_value.sival_ptr) += 1;
}

void timer(void (*myHandler)(int, siginfo_t *, void *))
{
    struct sigaction sa;
    sa.sa_flags = SA_SIGINFO;
    sa.sa_sigaction = myHandler;
    sigemptyset(&sa.sa_mask);
    sigaction(SIGRTMIN, &sa, nullptr); // nullptr
    // --
    struct sigevent sev;
    sev.sigev_notify = SIGEV_SIGNAL;
    sev.sigev_signo = SIGRTMIN;
    volatile int increment = 0;                     // *int
    sev.sigev_value.sival_ptr = (void *)&increment; // (void *)increment
    // --
    timer_t tid;
    timer_create(CLOCK_REALTIME, &sev, &tid);
    itimerspec its;
    its.it_value.tv_sec = 0;
    its.it_value.tv_nsec = 500 * ns_PER_ms; // 7500
    its.it_interval.tv_sec = 0;
    its.it_interval.tv_nsec = 500 * ns_PER_ms;
    timer_settime(tid, 0, &its, nullptr); // nullptr
    // . . . autres instructions en attendant l’arrivée du signal
    while (increment < 15)
    {
    }
    // sleep(30);
    timer_delete(tid);
}

int main()
{
    cout << "Hello World\n";
    cout << "Input: ";
    string data;
    getline(cin, data);
    cout << "Output: " << data << "\n\n";
    timer(handler1);
    return 0;
}
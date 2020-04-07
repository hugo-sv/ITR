#ifndef Timer_h_INCLUDED
#define Timer_h_INCLUDED
#include <iostream>
#include <signal.h>
#include "../../TD1/posixHelpers.h"
using namespace std;

class Timer
{
public:
    Timer();
    ~Timer();
    virtual void start(double duration_ms) = 0;
    void stop();
protected:
    timer_t tid;
    virtual void callback() = 0;
private:
    static void call_callback(int i, siginfo_t *si, void *);

};
#endif
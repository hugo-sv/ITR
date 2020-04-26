#ifndef td3_Timer_h_INCLUDED
#define td3_Timer_h_INCLUDED
#include <iostream>
#include <signal.h>
#include "../td1/posixHelpers.h"
using namespace td1;
using namespace std;

namespace td3
{
    
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

}

#endif
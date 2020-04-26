#ifndef td4_Thread_h_INCLUDED
#define td4_Thread_h_INCLUDED
#include "PosixThread.h"
using namespace std;

namespace td4
{

class Thread : public PosixThread
{
private:
    static void *call_run(void *v_thread);
    timespec startTime_;
    bool started;

protected:
    virtual void run() = 0;

public:
    timespec stopTime_;
    Thread();
    ~Thread();
    bool start();
    static void sleep_ms(double delay_ms);
    double startTime_ms();
    double stopTime_ms();
    double execTime_ms();
};

}
#endif
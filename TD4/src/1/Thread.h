#ifndef Thread_h_INCLUDED
#define Thread_h_INCLUDED
#include "PosixThread.h"
using namespace std;

class Thread : public PosixThread
{
private:
    static void *call_run(void *v_thread);
    timespec startTime_;

protected:
    virtual void run() = 0;

public:
    timespec stopTime_;
    Thread();
    ~Thread();
    void start();
    static void sleep_ms(double delay_ms);
    double startTime_ms();
    double stopTime_ms();
    double execTime_ms();
};
#endif
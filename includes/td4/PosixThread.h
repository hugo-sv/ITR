#ifndef PosixThread_h_INCLUDED
#define PosixThread_h_INCLUDED
#include <iostream>
#include <pthread.h>
#include "td1/posixHelpers.h"
using namespace std;

class PosixThread
{
private:
    pthread_t posixId;
    pthread_attr_t posixAttr;

protected:
    bool isActive;

public:
    class Exception
    {
    };
    PosixThread();
    PosixThread(pthread_t posixId);
    ~PosixThread();
    void start(void *(*)(void *), void *threadArg);
    void join();
    bool join(double timeout_ms);
    bool setScheduling(int schedPolicy, int priority);
    bool getScheduling(int *p_schedPolicy = nullptr, int *p_priority = nullptr);
};
#endif
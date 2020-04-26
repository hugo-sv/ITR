#ifndef Mutex_h_INCLUDED
#define Mutex_h_INCLUDED
#include <iostream>
#include <pthread.h>
#include <exception>
#include "../td1/posixHelpers.h"
using namespace td1;
using namespace std;

class Mutex
{
private:
    pthread_mutex_t posixId;
    pthread_cond_t posixCondId;

private:
    void lock();
    bool lock(double timeout_ms);
    bool trylock();
    void unlock();

public:
    class Lock;
    class TryLock;
    class Monitor;

public:
    Mutex();
    ~Mutex();
};

class Mutex::Monitor
{
protected:
    Monitor(Mutex &m);
    Mutex &m;

public:
    class TimeoutException;

public:
    void wait();
    bool wait(double timeout_ms);
    void notify();
    void notifyAll();
};

class Mutex::Monitor::TimeoutException : public exception
{
public:
    TimeoutException();
    const char *what() const noexcept override;
};

class Mutex::Lock : public Mutex::Monitor
{
public:
    Lock(Mutex &m);
    Lock(Mutex &m, double timeout_ms);
    ~Lock();
};

class Mutex::TryLock : public Mutex::Monitor
{
public:
    TryLock(Mutex &m);
    ~TryLock();
};

#endif
#include "td4/Thread.h"

Thread::Thread() : PosixThread()
{
    this->started = false;
    this->startTime_ = timespec_from_ms(0);
    this->stopTime_ = timespec_from_ms(0);
}
Thread::~Thread() {}
bool Thread::start()
{
    if (this->started)
    {
        return false;
    }
    this->startTime_ = timespec_now();
    this->stopTime_ = timespec_from_ms(0);
    this->PosixThread::start(Thread::call_run, this);
    this->started = true;
    return true;
}

void Thread::sleep_ms(double delay_ms)
{
    timespec_wait(timespec_from_ms(delay_ms));
}

double Thread::startTime_ms()
{
    return timespec_to_ms(this->startTime_);
}

double Thread::stopTime_ms()
{
    return timespec_to_ms(this->stopTime_);
}

double Thread::execTime_ms()
{
    if (this->started)
    {
        return timespec_to_ms(timespec_now()) - this->startTime_ms();
    }
    else
    {
        return this->stopTime_ms() - this->startTime_ms();
    }
}

void *Thread::call_run(void *v_thread)
{
    Thread *t_thread = (Thread *)v_thread;
    t_thread->run();
    t_thread->stopTime_ = timespec_now();
    t_thread->started = false;
    return v_thread;
}
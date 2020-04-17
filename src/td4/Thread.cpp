#include "td4/Thread.h"

Thread::Thread() : PosixThread() {}
Thread::~Thread() {}
void Thread::start()
{
    this->startTime_ = timespec_now();
    this->stopTime_ = timespec_from_ms(0);
    this->PosixThread::start(Thread::call_run, this);
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
    if (this->stopTime_ms() == 0)
    {
        return timespec_to_ms(timespec_now()) - this->startTime_ms();
    }
    return this->stopTime_ms() - this->startTime_ms();
}

void *Thread::call_run(void *v_thread)
{
    Thread *t_thread = (Thread *)v_thread;
    t_thread->run();
    t_thread->stopTime_ = timespec_now();
    return v_thread;
}
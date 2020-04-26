#include "PosixThread.h"

PosixThread::PosixThread()
{
    this->isActive = false;
    pthread_attr_init(&this->posixAttr);
}
PosixThread::PosixThread(pthread_t posixId)
{
    this->isActive = false;
    sched_param schedParams;
    int p_schedPolicy;
    if (!posixId || pthread_getschedparam(posixId, &p_schedPolicy, &schedParams) != 0)
    {
        throw Exception();
    }
    this->posixId = posixId;
    pthread_attr_init(&this->posixAttr);
    this->setScheduling(p_schedPolicy, schedParams.sched_priority);
}
PosixThread::~PosixThread()
{
    pthread_attr_destroy(&this->posixAttr);
}
void PosixThread::start(void *(*threadFunc)(void *), void *threadArg)
{
    if (!this->isActive)
    {
        this->isActive = true;
        pthread_create(&this->posixId, &this->posixAttr, threadFunc, threadArg);
    }
}
void PosixThread::join()
{
    pthread_join(this->posixId, nullptr);
    this->isActive = false;
}
bool PosixThread::join(double timeout_ms)
{
    struct timespec absTime = timespec_now() + timespec_from_ms(timeout_ms);
    bool output = !(bool)pthread_timedjoin_np(this->posixId, nullptr, &absTime);
    if (output)
    {
        this->isActive = false;
    }
    return output;
}
bool PosixThread::setScheduling(int schedPolicy, int priority)
{
    pthread_attr_setschedpolicy(&this->posixAttr, schedPolicy);
    struct sched_param schedParams;
    schedParams.sched_priority = priority;
    pthread_attr_setschedparam(&this->posixAttr, &schedParams);
    if (this->isActive)
    {
        struct sched_param param;
        param.sched_priority = priority;
        pthread_setschedparam(this->posixId, schedPolicy, &param);
    }
    return this->isActive;
}

// Default arguments ?
bool PosixThread::getScheduling(int *p_schedPolicy, int *p_priority)
{
    if (this->isActive)
    {
        struct sched_param schedParams;
        pthread_getschedparam(this->posixId, p_schedPolicy, &schedParams);
        *p_priority = schedParams.sched_priority;
    }
    else
    {
        struct sched_param schedParams;
        pthread_attr_getschedparam(&this->posixAttr, &schedParams);
        pthread_attr_getschedpolicy(&this->posixAttr, p_schedPolicy);
        *p_priority = schedParams.sched_priority;
    }
    return this->isActive;
}
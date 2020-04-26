#include "Semaphore.h"
using namespace td4;

Semaphore::Semaphore(unsigned int initCount = 0, unsigned int maxCount = UINT16_MAX) : count(initCount), maxCount(maxCount)
{
    this->m = Mutex();
}

Semaphore::Semaphore(unsigned int maxCount) : count(0), maxCount(maxCount)
{
    this->m = Mutex();
}

Semaphore::Semaphore() : count(0), maxCount(UINT16_MAX)
{
    this->m = Mutex();
}

void Semaphore::give()
{
    Mutex::Lock l(this->m);
    if (this->count > 0)
    {
        this->count--;
        l.notifyAll();
    }
}
void Semaphore::take()
{
    Mutex::Lock l(this->m);
    while (this->count >= this->maxCount)
    {
        l.wait();
    }
    this->count++;
}
bool Semaphore::take(double timeout_ms)
{
    Mutex::Lock l(this->m);
    bool result = true;
    while (this->count >= this->maxCount && result)
    {
        result = l.wait(timeout_ms);
    }
    if (result)
    {
        this->count++;
    }
    return result;
}
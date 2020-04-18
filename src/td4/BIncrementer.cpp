#include "BIncrementer.h"

BIncrementer::BIncrementer(void *data, int count, Mutex &mut) : Thread(), data(data), count(count), mut(mut) {}

void BIncrementer::run()
{
    for (int i = 0; i < this->count; i++)
    {
        Mutex::Lock lock = Mutex::Lock(this->mut);
        *(volatile int *)(this->data) += 1;
    }
}
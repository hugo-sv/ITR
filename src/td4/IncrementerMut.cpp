#include "IncrementerMut.h"

IncrementerMut::IncrementerMut(void *data, int count, Mutex &mut) : Thread(), data(data), count(count), mut(mut) {}

void IncrementerMut::run()
{
    for (int i = 0; i < this->count; i++)
    {
        Mutex::Lock lock = Mutex::Lock(this->mut);
        *(volatile int *)(this->data) += 1;
    }
}
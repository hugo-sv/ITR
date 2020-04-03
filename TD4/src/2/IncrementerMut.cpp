#include "IncrementerMut.h"

IncrementerMut::IncrementerMut(void *data, int count, Mutex &mut) : Thread(), data(data), count(count), mut(mut)
{
    cout << &this->mut << "\n";
}

void IncrementerMut::run()
{
    for (int i = 0; i < this->count; i++)
    {
        cout << &this->mut << "\n";
        Mutex::Lock lock = Mutex::Lock(this->mut);
        *(volatile int *)(this->data) += 1;
    }
}
#include "Incrementer.h"

Incrementer::Incrementer(void *data, int count) : Thread(), data(data), count(count) {}

void Incrementer::run()
{
    for (int i = 0; i < this->count; i++)
    {
        *(volatile int *)(this->data) += 1;
    }
}
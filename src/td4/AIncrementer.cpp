#include "AIncrementer.h"
using namespace td4;

AIncrementer::AIncrementer(void *data, int count) : Thread(), data(data), count(count) {}

void AIncrementer::run()
{
    for (int i = 0; i < this->count; i++)
    {
        *(volatile int *)(this->data) += 1;
    }
}
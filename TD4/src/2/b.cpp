#include <iostream>
#include "IncrementerMut.h"
#include "Mutex.h"
#include <vector>
using namespace std;

int main(void)
{
    int total = 1;
    int total_incrementers = 2;
    volatile int sum = 0;

    Mutex mut = Mutex();

    std::vector<IncrementerMut> incrementers;
    for (int i = 0; i < total_incrementers; i++)
    {
        incrementers.push_back(IncrementerMut((void *)&sum, total, mut));
    }

    for (IncrementerMut &incrementer : incrementers)
    {
        incrementer.start();
    }

    for (IncrementerMut &incrementer : incrementers)
    {
        incrementer.join();
    }
    return 0;
}
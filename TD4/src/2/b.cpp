#include <iostream>
#include "IncrementerMut.h"
#include "Mutex.h"
#include <vector>
using namespace std;

int main(void)
{
    int total = 1000000;
    int total_incrementers = 3;
    cout << "Expected result :" << total * total_incrementers << "\n";
    volatile int sum = 0;
    std::vector<IncrementerMut> incrementers;
    Mutex mut = Mutex();

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
    cout << "Result : " << sum << endl;
    return 0;
}
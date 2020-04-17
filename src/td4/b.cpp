#include <iostream>
#include "IncrementerMut.h"
#include "td4/Mutex.h"
#include <vector>
using namespace std;

int main(void)
{
    int total = 1000000;
    int total_incrementers = 3;
    cout << total_incrementers << " threads will count from 0 to " << total << ".\n";
    cout << "Expected result : " << total * total_incrementers << ".\n";
    volatile int sum = 0;
    std::vector<IncrementerMut> incrementers;
    Mutex mut = Mutex();
    // Creating Incrementer workers
    for (int i = 0; i < total_incrementers; i++)
    {
        incrementers.push_back(IncrementerMut((void *)&sum, total, mut));
    }
    // Starting the workers
    for (IncrementerMut &incrementer : incrementers)
    {
        incrementer.start();
    }
    // Joining the workers
    for (IncrementerMut &incrementer : incrementers)
    {
        incrementer.join();
    }
    cout << "Result : " << sum << endl;
    return 0;
}
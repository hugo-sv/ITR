#include <iostream>
#include "IncrementerMut.h"
#include "Mutex.h"
using namespace std;

int main(void)
{
    cout << "Experiment 1\n";
    volatile int a = 0;
    Mutex mut = Mutex();
    IncrementerMut b((void *)&a, 1000, mut);
    IncrementerMut c((void *)&a, 1000, mut);
    IncrementerMut d((void *)&a, 1000, mut);
    b.start();
    c.start();
    d.start();
    b.join();
    c.join();
    d.join();
    cout << "Total : " << a << endl;
    return 0;
}
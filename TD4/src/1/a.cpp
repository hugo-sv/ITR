#include <iostream>
#include "Incrementer.h"
using namespace std;

int main(void)
{
    {
        cout << "Experiment 1\n";
        volatile int a = 0;
        Incrementer b((void *)&a, 100000000);
        b.start();
        cout << "start : " << a << endl;
        Incrementer::sleep_ms(100);
        cout << "100 ms sleep : " << a << endl;
        b.join();
        cout << "Join : " << a << endl;
        cout << "Execution time = " << b.execTime_ms() << endl;
    }
    {
        cout << "Experiment 2\n";
        volatile int a = 0;
        Incrementer b((void *)&a, 100000000);
        b.start();
        cout << "start : " << a << endl;
        Incrementer::sleep_ms(100);
        cout << "100 ms sleep : " << a << endl;
        cout << "100 ms join -> " << b.join(100);
        // Ending line to write the rest because, otherwise, a would be printed before executiong join.
        cout << " : " << a << endl;
        cout << "500 ms join -> " << b.join(500);
        cout << " : " << a << endl;
        b.join();
        cout << "Join : " << a << endl;
        cout << "Execution time = " << b.execTime_ms() << endl;
    }
    {
        cout << "Experiment 3\n";
        volatile int a = 0;
        Incrementer b((void *)&a, 100000000);
        Incrementer c((void *)&a, 100000000);
        Incrementer d((void *)&a, 100000000);
        b.start();
        c.start();
        d.start();
        b.join();
        c.join();
        d.join();
        cout << "Total : " << a << endl;
    }
    return 0;
}
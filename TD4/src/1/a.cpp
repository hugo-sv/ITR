#include <iostream>
#include "Incrementer.h"
#include <vector>
using namespace std;

int main(void)
{
    {
        cout << "1 - Testing Join\n";
        volatile int a = 0;
        Incrementer b((void *)&a, 100000000);
        b.start();
        cout << "Execution time : " << b.execTime_ms() << " \t\tCounter Value : " << a << endl;
        Incrementer::sleep_ms(100);
        cout << "Execution time : " << b.execTime_ms() << " \t\tCounter Value : " << a << endl;
        cout << "Joining ...\n";
        b.join();
        cout << "Execution time : " << b.execTime_ms() << " \t\tCounter Value : " << a << endl;
    }
    {
        cout << "2 - Testing Join with timeout\n";
        volatile int a = 0;
        Incrementer b((void *)&a, 100000000);
        b.start();
        cout << "Execution time : " << b.execTime_ms() << " \t\tCounter Value : " << a << endl;
        Incrementer::sleep_ms(50);
        cout << "Execution time : " << b.execTime_ms() << " \t\tCounter Value : " << a << endl;
        cout << "Joining with 100ms timeout : " << b.join(100) << "\n";
        // Ending line to write the rest because, otherwise, a would be printed before executiong join.
        cout << "Execution time : " << b.execTime_ms() << " \t\tCounter Value : " << a << endl;
        cout << "Joining with 500ms timeout : " << b.join(500) << "\n";
        cout << "Execution time : " << b.execTime_ms() << " \t\tCounter Value : " << a << endl;
        cout << "Joining ...\n";
        b.join();
        cout << "Execution time : " << b.execTime_ms() << " \t\tCounter Value : " << a << endl;
    }
    {
        cout << "3 - Testing concurrency\n";
        int total = 1000000;
        int total_incrementers = 3;
        cout << total_incrementers << " threads will count from 0 to " << total << ".\n";
        cout << "Expected result : " << total * total_incrementers << ".\n";
        volatile int sum = 0;
        std::vector<Incrementer> incrementers;
        // Creating Incrementer workers
        for (int i = 0; i < total_incrementers; i++)
        {
            incrementers.push_back(Incrementer((void *)&sum, total));
        }
        // Starting the workers
        for (Incrementer &incrementer : incrementers)
        {
            incrementer.start();
        }
        // Joining the workers
        for (Incrementer &incrementer : incrementers)
        {
            incrementer.join();
        }
        cout << "Result : " << sum << endl;
        return 0;
    }
    return 0;
}
#include <iostream>
#include "AIncrementer.h"
#include <vector>
using namespace std;

int main(void)
{
    {
        cout << "1 - Testing Join" << endl;
        volatile int a = 0;
        AIncrementer b((void *)&a, 100000000);
        b.start();
        cout << "\tExecution time : " << b.execTime_ms() << " \t\tCounter Value : " << a << endl;
        cout << "\tSleeping 100 ms" << endl;
        AIncrementer::sleep_ms(100);
        cout << "\tExecution time : " << b.execTime_ms() << " \t\tCounter Value : " << a << endl;
        cout << "\tJoining ..." << endl;
        b.join();
        cout << "\tExecution time : " << b.execTime_ms() << " \t\tCounter Value : " << a << endl;
    }
    {
        cout << "2 - Testing Join with timeout" << endl;
        volatile int a = 0;
        AIncrementer b((void *)&a, 100000000);
        b.start();
        cout << "\tExecution time : " << b.execTime_ms() << " \t\tCounter Value : " << a << endl;
        cout << "\tSleeping 50 ms" << endl;
        AIncrementer::sleep_ms(50);
        cout << "\tExecution time : " << b.execTime_ms() << " \t\tCounter Value : " << a << endl;
        cout << "\tJoining with 50ms timeout : " << b.join(50) << endl;
        cout << "\tExecution time : " << b.execTime_ms() << " \t\tCounter Value : " << a << endl;
        cout << "\tJoining with 1000ms timeout : " << b.join(1000) << endl;
        cout << "\tExecution time : " << b.execTime_ms() << " \t\tCounter Value : " << a << endl;
        cout << "\tJoining ..." << endl;
        b.join();
        cout << "\tExecution time : " << b.execTime_ms() << " \t\tCounter Value : " << a << endl;
    }
    {
        cout << "3 - Testing concurrency" << endl;
        int total = 1000000;
        int total_incrementers = 10;
        cout << total_incrementers << " threads will count from 0 to " << total << ".\n";
        cout << "Expected result : " << total * total_incrementers << ".\n";
        volatile int sum = 0;
        std::vector<AIncrementer> incrementers;
        // Creating incrementer workers
        for (int i = 0; i < total_incrementers; i++)
        {
            incrementers.push_back(AIncrementer((void *)&sum, total));
        }
        // Starting the workers
        for (AIncrementer &incrementer : incrementers)
        {
            incrementer.start();
        }
        // Joining the workers
        for (AIncrementer &incrementer : incrementers)
        {
            incrementer.join();
        }
        cout << "Result : " << sum << endl;
        return 0;
    }
    return 0;
}
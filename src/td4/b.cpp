#include <iostream>
#include "BIncrementer.h"
#include "td4/Mutex.h"
#include <vector>
using namespace std;

int main(void)
{
    {
        cout << "1 - Testing concurrency" << endl;
        int total = 1000000;
        int total_incrementers = 10;
        cout << total_incrementers << " threads will count from 0 to " << total << ".\n";
        cout << "Expected result : " << total * total_incrementers << ".\n";
        volatile int sum = 0;
        std::vector<BIncrementer> incrementers;
        Mutex mut = Mutex();
        // Creating Incrementer workers
        for (int i = 0; i < total_incrementers; i++)
        {
            incrementers.push_back(BIncrementer((void *)&sum, total, mut));
        }
        // Starting the workers
        for (BIncrementer &incrementer : incrementers)
        {
            incrementer.start();
        }
        // Joining the workers
        for (BIncrementer &incrementer : incrementers)
        {
            incrementer.join();
        }
        cout << "Result : " << sum << endl;
    }
    {
        cout << "2 - Testing started field" << endl;
        int total = 1000000;
        volatile int sum = 0;
        Mutex mut = Mutex();
        BIncrementer incrementer = BIncrementer((void *)&sum, total, mut);
        cout << "Starting Thread (status : " << ((incrementer.start()) ? "success" : "failed") << ")" << endl;
        cout << "\tExecution time : " << incrementer.execTime_ms() << " \t\tCounter Value : " << sum << endl;
        cout << "Starting Thread (status : " << ((incrementer.start()) ? "success" : "failed") << ")" << endl;
        cout << "\tExecution time : " << incrementer.execTime_ms() << " \t\tCounter Value : " << sum << endl;
        cout << "Joining Thread..." << endl;
        incrementer.join();
        cout << "\tExecution time : " << incrementer.execTime_ms() << " \t\tCounter Value : " << sum << endl;
        cout << "Starting Thread (status : " << ((incrementer.start()) ? "success" : "failed") << ")" << endl;
        cout << "\tExecution time : " << incrementer.execTime_ms() << " \t\tCounter Value : " << sum << endl;
        cout << "Starting Thread (status : " << ((incrementer.start()) ? "success" : "failed") << ")" << endl;
        cout << "\tExecution time : " << incrementer.execTime_ms() << " \t\tCounter Value : " << sum << endl;
        cout << "Joining Thread..." << endl;
        incrementer.join();
        cout << "\tExecution time : " << incrementer.execTime_ms() << " \t\tCounter Value : " << sum << endl;
    }
    return 0;
}
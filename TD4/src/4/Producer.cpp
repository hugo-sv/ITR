#include "Producer.h"

Producer::Producer(Fifo<int> &f, int id, double timeout_ms) : Thread(), id(id), f(f), timeout_ms(timeout_ms) {}

void Producer::run()
{
    timespec deadline = timespec_now() + timespec_from_ms(this->timeout_ms);
    while (timespec_now() < deadline)
    {
        try
        {
            int task = this->f.pop(timespec_to_ms(deadline - timespec_now()));
            cout << this->id << "  ";
            for (int i = 0; i < task; i++)
            {
                cout << "  ";
            }
            cout << "Y"
                 << "\n";
            // Process
            timespec_wait(timespec_from_ms(10));
            if (task > 0)
            {
                this->f.push(task - 1);
                cout << this->id << "  ";
                for (int i = 0; i < task - 1; i++)
                {
                    cout << "  ";
                }
                cout << "V\n";

                if (task > 1)
                {
                    this->f.push(task - 2);
                    cout << this->id << "  ";
                    for (int i = 0; i < task - 2; i++)
                    {
                        cout << "  ";
                    }
                    cout << "V\n";
                }
            }
        }
        catch (...)
        {
            // timeout
            return;
        }
    }
    return;
}
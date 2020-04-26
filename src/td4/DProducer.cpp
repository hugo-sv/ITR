#include "DProducer.h"
using namespace td4;

DProducer::DProducer(Fifo<int> &f, int id, double timeout_ms) : Thread(), id(id), f(f), timeout_ms(timeout_ms) {}

void DProducer::run()
{
    timespec deadline = timespec_now() + timespec_from_ms(this->timeout_ms);
    // Producers will run until timeout
    while (timespec_now() < deadline)
    {
        try
        {
            // Picking a task from the Fifo
            int task = this->f.pop(timespec_to_ms(deadline - timespec_now()));
            // Processing
            timespec_wait(timespec_from_ms(10));
            // Adding two new tasks : task-1 and task-2, if possible
            if (task > 0)
            {
                this->f.push(task - 1);
                if (task > 1)
                {
                    this->f.push(task - 2);
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
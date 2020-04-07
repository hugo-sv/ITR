#include "td1/posixHelpers.h"
using namespace std;

void incr(unsigned int nLoops, double *pCounter)
{
    for (unsigned int i = 0; i < nLoops; i++)
    {
        (*pCounter)++;
    }
}

struct Data
{
    unsigned int nLoops;
    double *pCounter;
};

void *call_inc(void *v_data)
{
    Data *p_data = (Data *)v_data;
    incr(p_data->nLoops, p_data->pCounter);
    return v_data;
};

int main(int argc, char *argv[])
{
    unsigned int nLoops = 0;
    unsigned int nTasks = 0;
    if (argc > 1)
    {
        nLoops = strtoul(argv[1], nullptr, 10);
    }
    if (argc > 2)
    {
        nTasks = strtoul(argv[2], nullptr, 10);
    }
    double counter = 0.0;
    struct timespec tp, exec_time;

    Data data = {nLoops, &counter};
    pthread_t incrementThread[nTasks];
    tp = timespec_now();
    for (unsigned int i = 0; i < nTasks; i++)
    {
        // Starting threads
        pthread_create(&incrementThread[i], nullptr, call_inc, (void *)&data);
    }
    // Joining the threads
    for (unsigned int i = 0; i < nTasks; ++i)
        pthread_join(incrementThread[i], nullptr);
    // timespec_now() uses the Posix clock_gettime function
    exec_time = (timespec_now() - tp);
    cout << "Execution time (s) : " << timespec_to_ms(exec_time) / 1000 << "\n";
    cout << "Counter's value (s) : " << counter << "\n";
}
#include "../td1/posixHelpers.h"
using namespace std;
using namespace td1;

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

void *call_inc(void *data)
{
    Data *pData = (Data *)data;
    incr(pData->nLoops, pData->pCounter);
    return data;
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
    struct timespec start_ts, exec_ts;

    Data data = {nLoops, &counter};
    pthread_t incrementThread[nTasks];
    start_ts = timespec_now();
    for (unsigned int i = 0; i < nTasks; i++)
    {
        // Starting threads
        pthread_create(&incrementThread[i], nullptr, call_inc, (void *)&data);
    }
    // Joining the threads
    for (unsigned int i = 0; i < nTasks; ++i)
        pthread_join(incrementThread[i], nullptr);
    // timespec_now() uses the Posix clock_gettime function
    exec_ts = (timespec_now() - start_ts);
    cout << "Execution time (s) : " << timespec_to_ms(exec_ts) / 1000 << "\n";
    cout << "Counter's value (s) : " << counter << "\n";
}
#include "../td1/posixHelpers.h"
#include <tuple>
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

tuple<double, double> getExecutionTime(unsigned int nLoops, unsigned int nTasks, int ord)
{
    double counter = 0.0;
    struct timespec start_ts, exec_ts;

    // Parameters for main and tasks
    struct sched_param schedParam, schedParams;
    pthread_attr_t attr;
    pthread_attr_init(&attr);
    pthread_attr_setinheritsched(&attr, PTHREAD_EXPLICIT_SCHED);
    switch (ord)
    {
    case SCHED_FIFO:
        // Main
        schedParam.sched_priority = sched_get_priority_max(SCHED_FIFO);
        pthread_setschedparam(pthread_self(), SCHED_FIFO, &schedParam);
        // Tasks
        schedParams.sched_priority = 0;
        break;
    case SCHED_RR:
        // Main
        schedParam.sched_priority = sched_get_priority_max(SCHED_RR);
        pthread_setschedparam(pthread_self(), SCHED_RR, &schedParam);
        // Tasks
        schedParams.sched_priority = 0;
        break;
    default:
        // Main
        schedParam.sched_priority = sched_get_priority_max(SCHED_OTHER);
        pthread_setschedparam(pthread_self(), SCHED_OTHER, &schedParam);
        // Tasks
        schedParams.sched_priority = 0;
    }
    pthread_attr_setschedparam(&attr, &schedParams);

    Data data = {nLoops, &counter};
    pthread_t incrementThread[nTasks];
    start_ts = timespec_now();
    for (unsigned int i = 0; i < nTasks; i++)
    {
        // Starting threads
        pthread_create(&incrementThread[i], &attr, call_inc, (void *)&data);
    }
    // Destroying the attributes
    pthread_attr_destroy(&attr);
    // Joining the threads
    for (unsigned int i = 0; i < nTasks; ++i)
        pthread_join(incrementThread[i], nullptr);
    // timespec_now() uses the Posix clock_gettime function
    exec_ts = (timespec_now() - start_ts);
    return make_tuple(timespec_to_ms(exec_ts), counter);
}

int main(int argc, char *argv[])
{
    unsigned int nLoops = 0;
    unsigned int nTasks = 0;
    int ord = 0;
    if (argc > 1)
    {
        nLoops = strtoul(argv[1], nullptr, 10);
    }
    if (argc > 2)
    {
        nTasks = strtoul(argv[2], nullptr, 10);
    }
    if (argc > 3)
    {
        ord = strtoul(argv[3], nullptr, 10);
    }
    tuple<double, double> t = getExecutionTime(nLoops, nTasks, ord);
    cout << "Execution time (s) : " << get<0>(t) / 1000 << "\n";
    cout << "Counter's value (s) : " << get<1>(t) << "\n";
    cout << "Computing data to plot execution time graph...\n";
    cout << "Loops, Tasks, ExecutionTime\n";
    for (unsigned int i = 1; i <= 4; i++)
    {
        for (unsigned int iTasks = 1; iTasks <= 6; iTasks++)
        {
            t = getExecutionTime(10000000 * i, iTasks, SCHED_RR);
            cout << 10000000 * i << ", " << iTasks << ", " << get<0>(t) << "\n";
        }
    }
}
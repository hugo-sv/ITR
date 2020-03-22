#include "../TD1/posixHelpers.cpp"
#include <tuple>
using namespace std;

struct Data
{
    unsigned int nLoops;
    double *pCounter;
    bool mutexEnabled;
    pthread_mutex_t mutex;
};

void incr(unsigned int nLoops, double *pCounter)
{
    for (unsigned int i = 0; i < nLoops; i++)
    {
        (*pCounter)++;
    }
}

void incr_mutex(unsigned int nLoops, double *pCounter, pthread_mutex_t *mutex)
{
    for (unsigned int i = 0; i < nLoops; i++)
    {
        pthread_mutex_lock(mutex);
        (*pCounter)++;
        pthread_mutex_unlock(mutex);
    }
}

void *call_inc(void *v_data)
{
    Data *p_data = (Data *)v_data;
    if (p_data->mutexEnabled)
    {
        incr_mutex(p_data->nLoops, p_data->pCounter, &(p_data->mutex));
    }
    else
    {
        incr(p_data->nLoops, p_data->pCounter);
    }
    return v_data;
};

tuple<double, double> getExecutionTime(unsigned int nLoops, unsigned int nTasks, int ord, bool mutexEnabled)
{
    double counter = 0.0;
    struct timespec tp, exec_time;

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

    Data data = {nLoops, &counter, mutexEnabled};
    pthread_mutex_init(&data.mutex, nullptr);
    pthread_t incrementThread[nTasks];
    tp = timespec_now();
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
    // timespec_now() utilise la fonction Posix clock_gettime
    pthread_mutex_destroy(&data.mutex);
    exec_time = (timespec_now() - tp);
    return make_tuple(timespec_to_ms(exec_time), counter);
}

int main(int argc, char *argv[])
{
    unsigned int nLoops = 0;
    unsigned int nTasks = 0;
    int ord = 0;
    bool mutexEnabled = false;
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
    if (argc > 4)
    {
        mutexEnabled = (*argv[4] == '1');
    }
    tuple<double, double> t = getExecutionTime(nLoops, nTasks, ord, mutexEnabled);
    cout << "Temps d'execution (s) : " << get<0>(t) / 1000 << "\n";
    cout << "Valeur du compteur (s) : " << get<1>(t) << "\n";
}
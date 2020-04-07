#include "td1/posixHelpers.h"
#include "posixTimer.cpp"
#include <climits>
#include <tuple>
using namespace std;

unsigned incr(unsigned int nLoops, double *pCounter, volatile bool *pStop)
{
    unsigned i = 0;
    while (i < nLoops && !*pStop)
    {
        (*pCounter)++;
        i++;
    }
    return i;
}

void stopCallback(int, siginfo_t *si, void *)
{
    *(volatile bool *)(si->si_value.sival_ptr) = true;
}

// Return number of loops nombre de boucles performed in incr during t ms
double getL(int t)
{
    volatile bool stop = false;
    struct timespec value, interval;
    value = timespec_from_ms(t);
    interval = timespec_from_ms(0);
    // Starting timer
    timer_t tid = timer(stopCallback, value, interval, (void *)&stop);
    // Starting incrementation
    unsigned int nLoops = UINT_MAX;
    double counter = 0.0;
    incr(nLoops, &counter, &stop);
    // Stopping timer
    timer_delete(tid);
    return counter;
}

tuple<double, double> calib(int t1, int t2)
{
    double c1, c2, a, b;
    c1 = getL(t1 * ms_PER_s);
    c2 = getL(t2 * ms_PER_s);
    b = (c1 * t2 - c2 * t1) / (t2 - t1);
    a = (c1 - b) / (t1 * ms_PER_s);
    return make_tuple(a, b);
}

int main()
{
    // Computing a and b
    double a, b;
    tuple<double, double> t = calib(4, 6);
    a = get<0>(t);
    b = get<1>(t);
    cout << "a : " << a << " and b : " << b << "\n";
    // Verification
    double maxInc = 10000000000;
    cout << "Estimated exectution time for " << maxInc << " loops (ms) : " << (maxInc - b) / a << "\n";
    // Execution
    struct timespec tp, exec_time;
    tp = timespec_now();
    double inc = 0.0;
    while (inc < maxInc)
    {
        inc++;
    }
    exec_time = (timespec_now() - tp);
    cout << "Execution time (ms) : " << timespec_to_ms(exec_time) << "\n";
    // Comparing results
    cout << "Relative error : " << 100 * ((maxInc - b) / a - timespec_to_ms(exec_time)) / timespec_to_ms(exec_time) << "%\n";
}
#include "posixHelpers.h"
using namespace std;
using namespace td1;

void incr(unsigned int nLoops, double *pCounter)
{
    for (unsigned int i = 0; i < nLoops; i++)
    {
        (*pCounter)++;
    }
}

int main(int argc, char *argv[])
{
    unsigned int nLoops = 0;
    if (argc > 1)
    {
        nLoops = strtoul(argv[1], nullptr, 10);
    }
    double counter = 0.0;
    struct timespec start_ts, exec_ts;
    start_ts = timespec_now();
    incr(nLoops, &counter);
    cout << "Final Value : " << counter << "\n";
    // timespec_now() uses the Posix function clock_gettime
    exec_ts = (timespec_now() - start_ts);
    cout << "Execution time (s) : " << timespec_to_ms(exec_ts) / 1000 << "\n";
}
#include "td1/posixHelpers.h"
using namespace std;

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
    struct timespec tp, exec_time;
    tp = timespec_now();
    incr(nLoops, &counter);
    cout << "Valeur finale : " << counter << "\n";
    // timespec_now() uses the Posix function clock_gettime
    exec_time = (timespec_now() - tp);
    cout << "Temps d'execution (s) : " << timespec_to_ms(exec_time) / 1000 << "\n";
}
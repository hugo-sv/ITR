#ifndef Semaphore_h_INCLUDED
#define Semaphore_h_INCLUDED
#include "Mutex.h"
using namespace std;

class Semaphore
{
private:
    unsigned int count;
    unsigned int maxCount;
    Mutex m;

public:
    Semaphore(unsigned int initCount, unsigned int maxCount);
    Semaphore(unsigned int maxCount);
    Semaphore();
    void give();
    void take();
    bool take(double timeout_ms);
};
#endif
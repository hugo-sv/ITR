#ifndef Semaphore_h_INCLUDED
#define Semaphore_h_INCLUDED
#include "../2/Mutex.h"
using namespace std;

class Semaphore
{
private:
    unsigned int count;
    unsigned int maxCount;
    Mutex m;

public:
    Semaphore(unsigned int initCount, unsigned int maxCount);
    void give();
    void take();
    bool take(double timeout_ms);
};
#endif
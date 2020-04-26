#ifndef CProducer_h_INCLUDED
#define CProducer_h_INCLUDED
#include "Thread.h"
#include "Semaphore.h"
using namespace std;

class CProducer : public Thread
{
private:
    int id;
    void run();
    Semaphore &s;

public:
    CProducer(Semaphore &s, int id);
};
#endif
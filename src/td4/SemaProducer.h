#ifndef SemaProducer_h_INCLUDED
#define SemaProducer_h_INCLUDED
#include "td4/Thread.h"
#include "td4/Semaphore.h"
using namespace std;

class SemaProducer : public Thread
{
private:
    int id;
    void run();
    Semaphore &s;

public:
    SemaProducer(Semaphore &s, int id);
};
#endif
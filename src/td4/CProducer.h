#ifndef td4_CProducer_h_INCLUDED
#define td4_CProducer_h_INCLUDED
#include "Thread.h"
#include "Semaphore.h"
using namespace std;

namespace td4
{

class CProducer : public Thread
{
private:
    int id;
    void run();
    Semaphore &s;

public:
    CProducer(Semaphore &s, int id);
};

}
#endif
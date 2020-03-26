#ifndef Producer_h_INCLUDED
#define Producer_h_INCLUDED
#include "../1/Thread.h"
#include "Semaphore.h"
using namespace std;

class Producer : public Thread
{
private:
    int id;
    void run();
    Semaphore &s;

public:
    Producer(Semaphore &s, int id);
};
#endif
#ifndef BIncrementer_h_INCLUDED
#define BIncrementer_h_INCLUDED
#include "td4/Thread.h"
#include "td4/Mutex.h"
using namespace std;

class BIncrementer : public Thread
{
private:
    void *data;
    int count;
    void run();
    Mutex &mut;

public:
    BIncrementer(void *data, int count, Mutex &mut);
};
#endif
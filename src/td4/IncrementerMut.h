#ifndef IncrementerMut_h_INCLUDED
#define IncrementerMut_h_INCLUDED
#include "td4/Thread.h"
#include "td4/Mutex.h"
using namespace std;

class IncrementerMut : public Thread
{
private:
    void *data;
    int count;
    void run();
    Mutex &mut;

public:
    IncrementerMut(void *data, int count, Mutex &mut);
};
#endif
#ifndef td4_BIncrementer_h_INCLUDED
#define td4_BIncrementer_h_INCLUDED
#include "Thread.h"
#include "Mutex.h"
using namespace std;

namespace td4
{

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

}
#endif
#ifndef td4_AIncrementer_h_INCLUDED
#define td4_AIncrementer_h_INCLUDED
#include "Thread.h"
using namespace std;

namespace td4
{

class AIncrementer : public Thread
{
private:
    void *data;
    int count;
    void run();

public:
    AIncrementer(void *data, int count);
};

}

#endif
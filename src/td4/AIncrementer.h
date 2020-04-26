#ifndef AIncrementer_h_INCLUDED
#define AIncrementer_h_INCLUDED
#include "Thread.h"
using namespace std;

class AIncrementer : public Thread
{
private:
    void *data;
    int count;
    void run();

public:
    AIncrementer(void *data, int count);
};
#endif
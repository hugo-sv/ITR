#ifndef Incrementer_h_INCLUDED
#define Incrementer_h_INCLUDED
#include "Thread.h"
using namespace std;

class Incrementer : public Thread
{
private:
    void *data;
    int count;
    void run();

public:
    Incrementer(void *data, int count);
};
#endif
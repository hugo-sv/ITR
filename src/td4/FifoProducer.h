#ifndef FifoProducer_h_INCLUDED
#define FifoProducer_h_INCLUDED
#include "td4/Thread.h"
#include "td4/Fifo.hpp"
using namespace std;

class FifoProducer : public Thread
{
private:
    int id;
    void run();
    Fifo<int> &f;
    double timeout_ms;

public:
    FifoProducer(Fifo<int> &s, int id, double timeout_ms);
};
#endif
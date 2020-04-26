#ifndef DProducer_h_INCLUDED
#define DProducer_h_INCLUDED
#include "Thread.h"
#include "Fifo.hpp"
using namespace std;

class DProducer : public Thread
{
private:
    int id;
    void run();
    Fifo<int> &f;
    double timeout_ms;

public:
    DProducer(Fifo<int> &s, int id, double timeout_ms);
};
#endif
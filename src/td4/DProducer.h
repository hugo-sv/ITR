#ifndef td4_DProducer_h_INCLUDED
#define td4_DProducer_h_INCLUDED
#include "Thread.h"
#include "Fifo.hpp"
using namespace std;

namespace td4
{

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

}
#endif
#ifndef Producer_h_INCLUDED
#define Producer_h_INCLUDED
#include "../1/Thread.h"
#include "Fifo.hpp"
using namespace std;

class Producer : public Thread
{
private:
    int id;
    void run();
    Fifo<int> &f;
    double timeout_ms;

public:
    Producer(Fifo<int> &s, int id, double timeout_ms);
};
#endif
#ifndef ActiveObject_h_INCLUDED
#define ActiveObject_h_INCLUDED
#include "td4/Thread.h"
#include "td4/Fifo.hpp"
#include "Request.h"
using namespace std;

class ActiveObject : public Thread
{
protected:
    Fifo<Request *> reqFifo;
    void run();

public:
    ActiveObject(); // instanciate reqFifo
};
#endif
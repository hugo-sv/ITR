#ifndef ActiveObject_h_INCLUDED
#define ActiveObject_h_INCLUDED
#include "../../TD4/src/1/Thread.h"
#include "../../TD4/src/4/Fifo.hpp"
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
#ifndef td6_ActiveObject_h_INCLUDED
#define td6_ActiveObject_h_INCLUDED
#include "../td4/Thread.h"
#include "../td4/Fifo.hpp"
#include "Request.h"
using namespace std;
using namespace td4;

namespace td6
{

class ActiveObject : public Thread
{
protected:
    Fifo<Request *> reqFifo;
    void run();

public:
    ActiveObject(); // instanciate reqFifo
};

} // namespace td6
#endif
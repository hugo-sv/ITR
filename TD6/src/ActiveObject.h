#ifndef ActiveObject_h_INCLUDED
#define ActiveObject_h_INCLUDED
#include "../../TD4/src/1/Thread.h"
#include "RequestFifo.h"
using namespace std;

class ActiveObject : public Thread
{
protected:
    RequestFifo reqFifo;
    void run();

public:
    ActiveObject(); // instanciate reqFifo
};
#endif
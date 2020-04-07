#ifndef RequestFifo_h_INCLUDED
#define RequestFifo_h_INCLUDED
#include "../../TD4/src/4/Fifo.hpp"
#include "Request.h"
using namespace std;

// Request * : Object slicing
class RequestFifo : public Fifo<Request *>
{
private:
public:
    // Should we reimplement push/pop ?
    RequestFifo();
};
#endif
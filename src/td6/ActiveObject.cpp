#include "ActiveObject.h"

namespace td6
{

ActiveObject::ActiveObject()
{
    this->reqFifo = Fifo<Request *>();
}

void ActiveObject::run()
{
    while (true)
    {
        Request *req = this->reqFifo.pop();
        req->execute();
    }
}

}
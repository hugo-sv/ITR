#include "ActiveObject.h"

ActiveObject::ActiveObject()
{
    this->reqFifo = RequestFifo();
}

void ActiveObject::run()
{
    while (true)
    {
        Request *req = this->reqFifo.pop();
        req->execute();
    }
}
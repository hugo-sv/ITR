#include "ActiveObject.h"

void ActiveObject::run()
{
    while (true)
    {
        Request *req = this->reqFifo.pop();
        req->execute();
    }
}
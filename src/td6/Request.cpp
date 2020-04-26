#include "Request.h"

namespace td6
{

Request::Request()
{
    this->returnSema = Semaphore(1, 1);
}

void Request::waitReturn()
{
    this->returnSema.take();
}

}
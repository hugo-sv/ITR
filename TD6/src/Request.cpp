#include "Request.h"

Request::Request()
{
    this->returnSema = Semaphore(0, 1);
}

// Request::~Request() {}

void Request::waitReturn()
{
    this->returnSema.take();
}
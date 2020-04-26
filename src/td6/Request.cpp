#include "Request.h"

Request::Request()
{
    this->returnSema = Semaphore(1, 1);
}

// Request::~Request() {}

void Request::waitReturn()
{
    this->returnSema.take();
}
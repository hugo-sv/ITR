#ifndef Request_h_INCLUDED
#define Request_h_INCLUDED
#include "td4/Semaphore.h"
using namespace std;

class Request
{
protected:
    Semaphore returnSema;

public:
    Request();
    // ~Request();
    virtual void execute() = 0;
    void waitReturn();
};
#endif
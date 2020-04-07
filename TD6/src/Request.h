#ifndef Request_h_INCLUDED
#define Request_h_INCLUDED
#include "../../TD4/src/3/Semaphore.h"
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
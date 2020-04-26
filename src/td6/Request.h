#ifndef td6_Request_h_INCLUDED
#define td6_Request_h_INCLUDED
#include "../td4/Semaphore.h"
using namespace std;
using namespace td4;

namespace td6
{

class Request
{
protected:
    Semaphore returnSema;

public:
    Request();
    virtual void execute() = 0;
    void waitReturn();
};
} // namespace td6
#endif
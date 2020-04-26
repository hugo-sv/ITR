#ifndef ActiveCalc_h_INCLUDED
#define ActiveCalc_h_INCLUDED
#include "CrunchReq.h"
#include "ActiveObject.h"
using namespace std;

class ActiveCalc : public ActiveObject
{
private:
    Calculator *calc;

public:
    ActiveCalc();
    ~ActiveCalc();
    CrunchReq *async_crunch(double params); // Creates a CrunchReq object (and passes a calculator)
};
#endif
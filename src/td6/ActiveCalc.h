#ifndef td6_ActiveCalc_h_INCLUDED
#define td6_ActiveCalc_h_INCLUDED
#include "CrunchReq.h"
#include "ActiveObject.h"
using namespace std;

namespace td6
{

class ActiveCalc : public ActiveObject
{
private:
    Calculator *calc;

public:
    ActiveCalc();
    ~ActiveCalc();
    CrunchReq *async_crunch(double params); // Creates a CrunchReq object (and passes a calculator)
};

} // namespace td6
#endif
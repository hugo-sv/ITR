#ifndef td6_CrunchReq_h_INCLUDED
#define td6_CrunchReq_h_INCLUDED
#include "Request.h"
#include "Calculator.h"

using namespace std;

namespace td6
{

class CrunchReq : public Request
{
private:
    Calculator *calc;
    double param;
    double result;

public:
    CrunchReq(Calculator *calc, double param);
    void execute();
    double waitReturn();
};

} // namespace td6
#endif
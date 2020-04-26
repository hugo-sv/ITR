#ifndef CrunchReq_h_INCLUDED
#define CrunchReq_h_INCLUDED
#include "Request.h"
#include "Calculator.h"

using namespace std;

class CrunchReq : public Request
{
private:
    Calculator *calc;
    double param;
    double result;

public:
    CrunchReq(Calculator *calc, double param);
    // ~CrunchReq();
    void execute();
    double waitReturn();
};
#endif
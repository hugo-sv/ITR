#include "CrunchReq.h"

namespace td6
{

CrunchReq::CrunchReq(Calculator *calc, double param) : calc(calc), param(param) {}

double CrunchReq::waitReturn()
{
    this->returnSema.take();
    return result;
}

void CrunchReq::execute()
{
    result = calc->crunch(param);
    this->returnSema.give();
}

}
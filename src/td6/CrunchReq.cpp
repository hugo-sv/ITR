#include "CrunchReq.h"

CrunchReq::CrunchReq(Calculator *calc, double param) : calc(calc), param(param) {}

// CrunchReq::~CrunchReq() {}

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
#include "ActiveCalc.h"

ActiveCalc::ActiveCalc()
{
    this->calc = new Calculator();
}

ActiveCalc::~ActiveCalc()
{
    delete this->calc;
}

CrunchReq *ActiveCalc::async_crunch(double param)
{
    CrunchReq *req = new CrunchReq(this->calc, param);
    this->ActiveObject::reqFifo.push(req);
    return req;
}
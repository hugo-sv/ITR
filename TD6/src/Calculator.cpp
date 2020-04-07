#include "Calculator.h"
#include "../../TD1/posixHelpers.h"
#include <math.h>

Calculator::Calculator()
{
}
double Calculator::crunch(double param)
{
    double processing_time = sin(param) * 500;
    timespec_wait(timespec_from_ms(processing_time));
    return processing_time;
}
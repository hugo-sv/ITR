#include "Calculator.h"
#include "../td1/posixHelpers.h"
#include <math.h>
using namespace td1;

Calculator::Calculator()
{
}
double Calculator::crunch(double param)
{
    timespec_wait(timespec_from_ms(500));
    return param;
}
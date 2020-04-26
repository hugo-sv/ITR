#ifndef td6_Calculator_h_INCLUDED
#define td6_Calculator_h_INCLUDED
#include "../td4/Thread.h"
using namespace std;
using namespace td4;

namespace td6
{

class Calculator
{
private:
public:
    Calculator();
    double crunch(double param);
};
} // namespace td6
#endif
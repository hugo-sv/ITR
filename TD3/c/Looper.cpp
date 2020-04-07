#include "Looper.h"

double Looper::runLoop(double nLoops = __DBL_MAX__)
{
    while(!doStop && iLoop < nLoops)
    {
        iLoop += 1.0;
    }
    return iLoop;
}

double Looper::getSample()
{
    return iLoop;
}

double Looper::stopLoop()
{
    doStop = true;
    return iLoop;
}
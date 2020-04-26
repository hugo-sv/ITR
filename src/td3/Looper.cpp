#include "Looper.h"
using namespace td3;

double Looper::runLoop(double nLoops)
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
#ifndef td3_Looper_h_INCLUDED
#define td3_Looper_h_INCLUDED

namespace td3
{

class Looper 
{
public:
    double runLoop(double nLoops = __DBL_MAX__);
    double getSample();
    double stopLoop();

private:
    volatile bool doStop;
    volatile double iLoop;
};

}
#endif
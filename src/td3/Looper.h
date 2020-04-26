#ifndef Looper_h_INCLUDED
#define Looper_h_INCLUDED

class Looper 
{
public:
    double runLoop(double nLoops = __DBL_MAX__);
    double getSample();
    double stopLoop();
protected:
private:
    volatile bool doStop;
    double iLoop;
};
#endif
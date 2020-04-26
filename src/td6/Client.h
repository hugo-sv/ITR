#ifndef Client_h_INCLUDED
#define Client_h_INCLUDED
#include "../td4/Thread.h"
#include "ActiveCalc.h"

using namespace std;

class Client : public Thread
{
private:
    double crunchSeed;
    ActiveCalc *acalc;

protected:
    void run() override;

public:
    Client(double crunchSeed, ActiveCalc *acalc);
};
#endif
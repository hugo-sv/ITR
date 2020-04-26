#ifndef td6_Client_h_INCLUDED
#define td6_Client_h_INCLUDED
#include "../td4/Thread.h"
#include "ActiveCalc.h"

using namespace std;
using namespace td4;

namespace td6
{

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

} // namespace td6
#endif
#include "Client.h"
#include "CrunchReq.h"

namespace td6
{

Client::Client(double crunchSeed, ActiveCalc *acalc) : crunchSeed(crunchSeed), acalc(acalc) {}

void Client::run()
{
    cout << "Client " << this->crunchSeed << " started his job\n";
    timespec start_ts = timespec_now();
    CrunchReq *req = acalc->async_crunch(this->crunchSeed);
    // Processing other instructions ...
    timespec_wait(timespec_from_ms(1500));
    // Waiting for results
    double result = req->waitReturn();
    double duration_ms = timespec_to_ms(timespec_now() - start_ts);
    if (result == this->crunchSeed && duration_ms <= 5050)
    {
        cout << "Client " << this->crunchSeed << " received the expected result in " << duration_ms << endl;
    }
    else if (result != this->crunchSeed)
    {
        cout << "Client " << this->crunchSeed << " received an unexpected result : " << result << " in " << duration_ms << endl;
    }
    else
    {
        cout << "Client " << this->crunchSeed << " received the expected result but waited too long : " << duration_ms << endl;
    }
}

}
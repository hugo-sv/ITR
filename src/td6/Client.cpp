#include "Client.h"
#include "CrunchReq.h"

Client::Client(double crunchSeed, ActiveCalc *acalc) : crunchSeed(crunchSeed), acalc(acalc) {}

void Client::run()
{
    cout << "Client " << this->crunchSeed << " started his job\n";
    timespec start_time = timespec_now();
    CrunchReq *req = acalc->async_crunch(this->crunchSeed);
    // Processing other instructions ...
    timespec_wait(timespec_from_ms(1500));
    // Waiting for results
    double result = req->waitReturn();
    double duration = timespec_to_ms(timespec_now() - start_time);
    if (result == this->crunchSeed && duration <= 5050)
    {
        cout << "Client " << this->crunchSeed << " received the expected result in " << duration << endl;
    }
    else if (result != this->crunchSeed)
    {
        cout << "Client " << this->crunchSeed << " received an unexpected result : " << result << " in " << duration << endl;
    }
    else
    {
        cout << "Client " << this->crunchSeed << " received the expected result but waited too long : " << duration << endl;
    }
}
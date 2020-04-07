#include "Client.h"
#include "CrunchReq.h"

Client::Client(double crunchSeed, ActiveCalc *acalc) : crunchSeed(crunchSeed), acalc(acalc) {}

void Client::run()
{
    cout << "Client " << this->crunchSeed << " started his job\n";
    timespec start_time = timespec_now();
    CrunchReq *req = acalc->async_crunch(this->crunchSeed);
    // ...
    double result = req->waitReturn();
    cout << "Client " << this->crunchSeed << " recieved a result : " << result << " in " << timespec_to_ms(timespec_now() - start_time) << "\n";
    // deleting object of polymorphic class type 'CrunchReq' which has non-virtual destructor might cause undefined behavior
    // delete req;
}
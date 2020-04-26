#include <iostream>
#include <vector>
#include <memory>
#include "ActiveCalc.h"
#include "Client.h"
using namespace std;
using namespace td6;

int main(void)
{
    // Instatiation of Calculator and clients
    ActiveCalc acalc = ActiveCalc();
    std::vector<std::unique_ptr<Client>> clients(10);
    double seed = 0;
    for (auto &client : clients)
    {
        client.reset(new Client(seed, &acalc));
        // Increaing seed
        seed += 1;
    }

    // Starting calculator and clients
    timespec start_ts = timespec_now();
    acalc.start();

    for (auto &client : clients)
    {
        client->start();
        timespec_wait(timespec_from_ms(1));
    }

    // Waiting for all clients to be done
    for (auto &client : clients)
    {
        client->join();
    }
    double duration_ms = timespec_to_ms(timespec_now() - start_ts);
    if (duration_ms < 5100)
    {
        cout << "All jobs have been processed within " << duration_ms << " ms." << endl;
    }
    else
    {
        cout << "Overall processing time exceeded 5100 ms : " << duration_ms << " ms." << endl;
    }
}
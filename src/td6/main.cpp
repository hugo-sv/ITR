#include <iostream>
#include <vector>
#include <memory>
#include "ActiveCalc.h"
#include "Client.h"
using namespace std;

int main(void)
{
    ActiveCalc acalc = ActiveCalc();
    std::vector<std::unique_ptr<Client>> clients(10);
    double seed = 2;
    for (auto &client : clients)
    {
        client.reset(new Client(seed, &acalc));
        seed *= 2;
    }

    acalc.start();

    for (auto &client : clients)
    {
        client->start();
    }

    for (auto &client : clients)
    {
        client->join();
    }
}
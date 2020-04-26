#include <iostream>
#include "Fifo.hpp"
#include "DProducer.h"
using namespace std;

int main(void)
{
    int nProd = 5;
    int nCons = 2;
    double producersTimeout = 500;
    Fifo<int> f = Fifo<int>();
    // Adding tasks
    for (int i = 0; i < nProd; i++)
    {
        f.push(nProd - i);
    }
    // Creating Producers
    std::vector<DProducer> producers;
    for (int i = 0; i < nCons; i++)
    {
        producers.push_back(DProducer(f, i, producersTimeout));
    }
    // Starting jobs
    for (auto &&producer : producers)
    {
        timespec_wait(timespec_from_ms(7));
        producer.start();
    }
    // Waiting for jobs
    for (auto &&producer : producers)
    {
        producer.join();
    }
    // Check if Fifo is empty, and all task have been consummed.
    if (f.empty())
    {
        cout << "Fifo is empty, all tasks have been consummed." << endl;
    }
    else
    {
        cout << "Fifo is not empty, There are remaining tasks to consume." << endl;
    }
    return 0;
}
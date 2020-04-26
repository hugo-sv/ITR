#include <iostream>
#include "Semaphore.h"
#include "CProducer.h"
#include <vector>
using namespace std;

int main(void)
{
    int nProd = 10;
    int nCons = 5;
    // Initially nCons tokens are available (There can only be nCons consummers at the same time)
    Semaphore s = Semaphore(0, nCons);
    // Creating nProd Producers
    std::vector<CProducer> producers;
    for (int i = 0; i < nProd; i++)
    {
        producers.push_back(CProducer(s, i));
    }
    timespec start_time = timespec_now();
    // Starting jobs
    for (auto &&producer : producers)
    {
        producer.start();
    }
    // Waiting for jobs
    for (auto &&producer : producers)
    {
        producer.join();
    }
    // Each producer require 100 ms to perform a task. With 10 producers and 5 tokens, all tasks should be performed in 200ms
    cout << "Tasks realised in " << timespec_to_ms(timespec_now() - start_time) << " ms (expected : 200ms)\n";
    return 0;
}
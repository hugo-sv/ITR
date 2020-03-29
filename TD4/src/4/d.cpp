#include <iostream>
#include "Fifo.hpp"
#include "Producer.h"
using namespace std;

int main(void)
{
    /*
    Testez la classe en y accédant de manière concurrente par de multiples tâches productrices et consommatrices. 
    Pour cela, utilisez une fifo de nombres entiers Fifo<int> et faites produire par chaque tâche productrice une série d’entiers de 0 à n. 
    Mettez en place un mécanisme pour vérifier que tous les entiers produits par les tâches productrices ont bien été reçus par les tâches consommatrices.
    */
    int nProd = 5;
    int nCons = 2;
    Fifo<int> f = Fifo<int>();
    // Creation du Producers
    std::vector<Producer> producers;
    for (int i = 0; i < nCons; i++)
    {
        producers.push_back(Producer(f, i, 5000));
    }
    // Adding tasks
    for (int i = 0; i < nProd; i++)
    {
        f.push(nProd - i);
    }
    timespec start_time = timespec_now();
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
    cout << "Taches réalisées en " << timespec_to_ms(timespec_now() - start_time) << " ms\n";
    // TODO Vérifier que tous les entiers produits par les tâches productrices ont bien été reçus par les tâches consommatrices.

    return 0;
}
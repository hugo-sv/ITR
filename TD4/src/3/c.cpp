#include <iostream>
#include "Semaphore.h"
#include "Producer.h"
#include <vector>
using namespace std;

int main(void)
{
    /*
    Pour tester votre classe, instanciez un sémaphore initialement vide partagé par 2 types de tâches :
        – une tâche productrice qui « donne » des jetons au sémaphore ;
        – une tâche consommatrice qui « prend » des jetons au sémaphore ;
    dans votre main, faites tourner nCons tâches consommatrices et nProd tâches productrices et vérifiez que tous les jetons crées ont bien été consommés.
    */
    int nProd = 10;
    int nCons = 5;
    Semaphore s = Semaphore(0, nCons);
    // Creation du Producers
    std::vector<Producer> producers;
    for (int i = 0; i < nProd; i++)
    {
        producers.push_back(Producer(s, i));
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
    cout << "Taches réalisées en " << timespec_to_ms(timespec_now() - start_time) << " ms\n";
    return 0;
}
#include "posixTimer.cpp"
using namespace std;

// sig is unused in this function
void callback(int, siginfo_t *si, void *)
{
    std::cout << *(volatile int *)(si->si_value.sival_ptr) << std::endl;
    *(volatile int *)(si->si_value.sival_ptr) += 1;
}

int main()
{
    // Implémentez un timer Posix périodique de fréquence 2 Hz imprimant un message avec la valeur d’un compteur régulièrement incrémenté.
    struct timespec value, interval;
    value = timespec_from_ms(500);
    interval = timespec_from_ms(500);
    volatile int increment = 0;
    timer_t tid = timer(callback, value, interval, (void *)&increment);
    // Le programme doit s’arrêter après 15 incrémentations.
    while (increment < 15)
    {
    }
    timer_delete(tid);
    cout << "The program stopped after 15 iterations\n";
}
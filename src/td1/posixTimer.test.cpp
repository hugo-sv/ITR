#include "posixTimer.cpp"
using namespace std;

// sig is unused in this function
void callback(int, siginfo_t *si, void *)
{
    // printing a message
    std::cout << *(volatile int *)(si->si_value.sival_ptr) << std::endl;
    // Updating the counter value
    *(volatile int *)(si->si_value.sival_ptr) += 1;
}

int main()
{
    // Periodic Posix Timer with 2 Hz frequency
    struct timespec value, interval;
    // with 2 Hz frequency
    value = timespec_from_ms(500);
    interval = timespec_from_ms(500);
    volatile int increment = 0;
    timer_t tid = timer(callback, value, interval, (void *)&increment);
    // The program must stops after 15 iterations
    while (increment < 15)
    {
    }
    timer_delete(tid);
    cout << "The program stopped after 15 iterations\n";
}
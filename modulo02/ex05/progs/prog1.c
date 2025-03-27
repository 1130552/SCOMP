#include <stdio.h>
#include <unistd.h>

int main() {
    for (long i = 1000; i < 2000; i++) {
        printf("Process %d: %ld\n", getpid(), i);
        usleep(10000);  // Slow it down a bit
    }
    return 0;
}
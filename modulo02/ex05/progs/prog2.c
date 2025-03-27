#include <stdio.h>
#include <unistd.h>

int main() {
    for (long i = 2000; i < 3000; i++) {
        printf("Process %d: %ld\n", getpid(), i);
        usleep(10000);
    }
    return 0;
}
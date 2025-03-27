#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>

int main() {
    srand(time(NULL));
    int count = 0;
    while (count < 1000) {
        printf("Process %d: %d\n", getpid(), rand() % 100);
        usleep(50000);
        count++;
    }
    return 0;
}
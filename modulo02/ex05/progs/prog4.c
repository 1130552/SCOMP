#include <stdio.h>
#include <unistd.h>

int main() {
    long a = 0, b = 1, temp;
    while (a < 2000000000) {
        printf("Process %d: %ld\n", getpid(), a);
        temp = a + b;
        a = b;
        b = temp;
        usleep(50000);
    }
    return 0;
}
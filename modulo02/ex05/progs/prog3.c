#include <stdio.h>
#include <unistd.h>

int main() {
    int count = 0;
    while (count < 10) {
        for (char c = 'A'; c <= 'Z'; c++) {
            printf("Process %d: %c\n", getpid(), c);
            usleep(50000);
        }
        count++;
    }
    return 0;
}
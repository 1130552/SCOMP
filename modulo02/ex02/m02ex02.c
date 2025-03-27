#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <signal.h>
#include <string.h>
#include "divide.h"

void handle_division_zero(int signo) {
    write(STDOUT_FILENO, "\nNao da para dividir por zero.\n", 31);
    _exit(1);
}

int main() {
    struct sigaction act;
    memset(&act, 0, sizeof(struct sigaction));
    sigemptyset(&act.sa_mask);
    
    act.sa_handler = handle_division_zero;

    sigaction(SIGFPE, &act, NULL);

    printf("Resultado divisao: %d\n", divide(4,5));

    sleep(4);

    printf("Resultado dividir por zero: %d", divide(4,0));

    return 0;
}
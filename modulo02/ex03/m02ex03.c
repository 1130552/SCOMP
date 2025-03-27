#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <signal.h>
#include <string.h>

void handle_sigsegv(int signo) {
    write(STDOUT_FILENO, "\nI got signal SIGSEGV\n", 22);
    _exit(1);
}

int main() {
    struct sigaction act;
    memset(&act, 0, sizeof(struct sigaction));
    sigemptyset(&act.sa_mask);

    act.sa_handler = handle_sigsegv;

    sigaction(SIGSEGV, &act, NULL);

    int a;
    a = *(int *)0;

    return 0;
}
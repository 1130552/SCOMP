#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>
#include "create_twins.h"

int main() {
    const int twin_pairs = 3;
    pid_t twins[twin_pairs * 2];
    pid_t pid;
    char twin_output;
    int status;
    int exit_status;

    for(int i = 0; i < twin_pairs; i++) {
        twin_output = create_twins(twins + (i * 2));
        if (twin_output == 'a') {
            printf("Pair: %d Twin: 1 PPID: %d PID: %d\n", i, getppid(), getpid());
            exit('a');
        } else if (twin_output == 'b') {
            printf("Pair: %d Twin: 2 PPID: %d PID: %d\n", i, getppid(), getpid());
            exit('b');
        }
    }

    for(int i = 0; i < (twin_pairs * 2); i++) {
        status = 0;
        waitpid(twins[i], &status, 0);
        if (WIFEXITED(status))
        {
            exit_status = WEXITSTATUS(status);
            printf("Child %d finished with exit status %c\n", (i + 1), exit_status);
        }
        
    }

    return 0;
}
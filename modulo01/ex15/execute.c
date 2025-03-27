#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <errno.h>
#include "execute.h"

void execute(int argc, char *argv[]) {
    pid_t pid = 0;
    int command_ind = 0;

    for(int i = 0; i < argc; i++) {
        pid = fork();

        if(pid == 0) {
            command_ind = i;
            break;
        }
    }

    if(pid == 0) {
        execlp(argv[command_ind], argv[command_ind], (char*)NULL);
        printf("execlp failed. errono is [%d]\n", errno);
        perror("Error message:");
        exit(EXIT_FAILURE);
    }

    for(int i = 0; i < argc; i++) {
        int status = 0;
        wait(&status);
        if(WEXITSTATUS(status)) {
            printf("Child finished with EXIT: %d\n", WEXITSTATUS(status));
        }
    }  
}
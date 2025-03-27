#include <stdio.h>      // For printf(), perror()
#include <stdlib.h>     // For exit()
#include <unistd.h>     // For pipe(), fork(), read(), write(), close()
#include <sys/types.h>  // For pid_t

#define BUFFER_SIZE 80

int main() {

    int fd[2] = {0};
    enum extremidade{LEITURA = 0, ESCRITA = 1};

    if(pipe(fd) == -1) {
        perror("pipe failed.");
        exit(1);
    }

    pid_t pid = fork();

    if(pid == -1) {
        perror("fork failed.");
        exit(1);
    }

    if(pid == 0) {
        close(fd[ESCRITA]);
        char leitura[BUFFER_SIZE];
        read(fd[LEITURA], leitura, BUFFER_SIZE);
        printf("Read %s from father.\n", leitura);
        close(fd[LEITURA]);
    } else {
        close(fd[LEITURA]);
        printf("Father PID: %d\n", getpid());
        char pid_string[BUFFER_SIZE];
        snprintf(pid_string, sizeof(pid_string), "%d", getpid());
        write(fd[ESCRITA], pid_string, sizeof(pid));
        close(fd[ESCRITA]);
    }

    return 0;
}
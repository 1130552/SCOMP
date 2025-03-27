#include <stdio.h>      // For printf(), perror()
#include <stdlib.h>     // For exit()
#include <unistd.h>     // For pipe(), fork(), read(), write(), close()
#include <sys/types.h>  // For pid_t

#define BUFFER_SIZE 256

int main() {
    int fd[2];
    enum extremidades {LEITURA = 0, ESCRITA = 1};
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
        char read_txt[256];

        int n = read(fd[LEITURA], read_txt, BUFFER_SIZE);
        read_txt[n] = '\0';
        printf("Txt from father:%s\n", read_txt);
        printf("n = %d\n", n);
        close(fd[LEITURA]);
    } else {
        close(fd[LEITURA]);
        dup2(fd[ESCRITA], 1);
        close(fd[ESCRITA]);
        execlp("cat", "cat", "contents.txt", NULL);
    }
}
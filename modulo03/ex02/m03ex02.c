#include <stdio.h>      // For printf(), perror()
#include <stdlib.h>     // For exit()
#include <unistd.h>     // For pipe(), fork(), read(), write(), close()
#include <sys/types.h>  // For pid_t

#define BUFFER_SIZE 256

int main() {
    int fd[2] = {0};
    enum extremidades {LEITURA = 0, ESCRITA = 1};

    if(pipe(fd) == -1) {
        perror("fork failed.");
        exit(1);
    }

    pid_t pid = fork();

    if(pid == -1) {
        perror("fork failed.");
        exit(1);
    }

    if(pid == 0) {
        close(fd[ESCRITA]);
        int read_num;
        char read_name[24];

        read(fd[LEITURA], &read_num, 4);
        read(fd[LEITURA], read_name, 24);

        printf("Read num: %d\nRead Name: %s\n", read_num, read_name);

        close(fd[LEITURA]);

    } else {
        close(fd[LEITURA]);

        printf("Input number.\n");
        int num = 0;
        scanf("%d", &num);
        printf("Input name.\n");
        char name[24];
        scanf("%23s", name);

        write(fd[ESCRITA], &num, sizeof(num));
        write(fd[ESCRITA], name, sizeof(name));

        close(fd[ESCRITA]);
    }

}
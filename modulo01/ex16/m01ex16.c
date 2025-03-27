#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>

int main() {
    pid_t pid = 0;
    char command[50];
    char **argv = NULL;
    int count = 0;

    while(strcmp(command, "end") != 0){
        printf("$DGOMES-SHELL- ");
        fgets(command, sizeof(command), stdin);
        count = 0;

        command[strcspn(command, "\n")] = '\0';
        argv = NULL;
        
        char *token = strtok(command, " "); 
        while (token != NULL) {
            argv = realloc(argv, (count + 1) * sizeof(char *));
            argv[count] = strdup(token);
            count++;
            token = strtok(NULL, " ");
        }
        argv = realloc(argv, (count + 1) * sizeof(char *));
        argv[count] = NULL;

        if(strcmp(command, "end") != 0){
            pid = fork();

            if(pid > 0) {
                wait(NULL);
            } else {
                execvp(argv[0], argv);
                printf("Error: %d\n", errno);
                perror("Error message: ");
                exit(EXIT_FAILURE);
            }
        }

        for (int i = 0; i < count; i++) {
            free(argv[i]);
        }
        free(argv);

    }

    return 0;
}
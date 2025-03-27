#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <time.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int array[100000];
    const int NUM_CHILDREN = 5;
    int child_num = -1;
    int found = 0;
    srand(time(NULL) ^ getpid()); 
    int rand_num = rand() % 100000;
    //rand_num = 101000;

    printf("Looking for number: %d\n", rand_num);

    for(int i = 0; i < 100000; i++) {
        array[i] = i;
    }

    for(int i = 0; i < NUM_CHILDREN; i++) {
        pid_t pid = fork();

        if(pid == 0) {
            child_num = i;
            break;
        }
    }

    if(child_num > -1) {
        int lim_inf = (20000 * child_num);
        int lim_sup = lim_inf + 20001;
       
        for(int i = lim_inf; i < lim_sup; i++) {
            if(array[i] == rand_num) {
                printf("Number found at index: %d\n", i);
                exit(child_num + 1);
            }
        }

        exit(0);
    } else {
        for(int i = 0; i < NUM_CHILDREN; i++) {
            int status = 0;
            pid_t wpid = wait(&status);
            printf("Child %d finished.\n", wpid);
            if(WIFEXITED(status)) {
                if(WEXITSTATUS(status) != 0) {
                    printf("!Child %d found the number with pid: %d\n", wpid);
                    found = 1;
                } 
            }
        }

        if (found == 0) {
            printf("ERROR: Number not found in array.\n");
        }
        
    }

    return 0;
}
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>

int main() {
    const int NUM_CHILDREN = 6;
    pid_t pids[NUM_CHILDREN];
    int child_num;

    for(int i = 0; i < NUM_CHILDREN; i++) {
        pids[i] = fork();

        if(pids[i] == 0) {
            child_num = i;
            break;
        }
        child_num = -1;
    }

    if(child_num > -1) {
        int inf_lim = (200000 * child_num) + 1;
        int sup_lim = inf_lim + 199999;

        for(int i = inf_lim; i <= sup_lim; i++) {
            printf("%d\n", i);
        }
    } else {
        for(int i = 0; i < NUM_CHILDREN; i++){
            wait(NULL);
        }
        sleep(4);
    }

    for(int i = 1; i <= 1200000; i++){
        printf("%d\n", i);
    }

    return 0;
}
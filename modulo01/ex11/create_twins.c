#include "create_twins.h"
#include <unistd.h>

char create_twins(pid_t list[]) {

    for(int i = 0; i < NUM_TWINS; i++) {
        list[i] = fork();

        if(list[i] == 0) {
            return (i == 0) ? 'a':'b';
        }
    }

    return 'p';
}
#include <sys/types.h>
#include "schedule.h"

int main(int argc, char *argv[]) {
    pid_t *pids = malloc((argc - 1) * sizeof(pid_t));

    if (argc < 2) {
        perror("Not enough arguments.");
        return 1;
    }

    create_processes(argc - 1, &argv[1], pids);
    schedule_processes(argc - 1, pids);

    free(pids);

}
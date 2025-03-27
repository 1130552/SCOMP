#include "schedule.h"

void create_processes(int num_procs, char *programs[], pid_t pids[]){
    for(int i = 0; i < num_procs; i++) {
        pids[i] = fork();

        if(pids[i] < 0) {
            perror("fork failed.");
            exit(1);
        }

        if (pids[i] == 0){
            raise(SIGSTOP);
            char program_path[1024];
            snprintf(program_path, sizeof(program_path), "./progs/%s", programs[i]);
            execl(program_path, programs[i], NULL);
            perror("Exec failed.");
            exit(1);
        }
    }
}

void schedule_processes(int num_procs, pid_t pids[]){
    int completed = 0;
    int current_proc = 0;
    int status;
    pid_t pids_completed[5] ={0};

    while(completed < num_procs) {

        if(pids_completed[current_proc] != pids[current_proc]){
            status = 0;
            kill(pids[current_proc], SIGCONT);
            sleep(TIME_SLICE);
            kill(pids[current_proc], SIGSTOP);
    
            if(waitpid(pids[current_proc], &status, WNOHANG) > 0) {
                if (WIFEXITED(status)) {
                    printf("Process %d finished with exit status %d\n", current_proc + 1, WEXITSTATUS(status));
                    completed++;
                    pids_completed[current_proc] = pids[current_proc];
                }
            }
        }

        current_proc = (current_proc + 1) % num_procs;
    }
}

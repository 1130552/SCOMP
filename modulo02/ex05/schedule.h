#ifndef SCHEDULE_H
#define SCHEDULE_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <signal.h>

#define TIME_SLICE 5

void create_processes(int num_procs, char *programs[], pid_t pids[]);

void schedule_processes(int num_procs, pid_t pids[]);

void cleanup_processes(int num_procs, pid_t pids[]);

#endif
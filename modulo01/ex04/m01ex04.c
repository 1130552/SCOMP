#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>

int main() {
	pid_t pids[3];
	int f;
	int num;
	
	for(f = 0; f<3; f++) {
		pids[f] = fork();
		
		if( pids[f] > 0 ) {
			printf("I am the father \n");
		} else {
			num = f + 1;
			break;
		}
	}
	
	if(num > 0) {
		exit(num);
	}
	
	for(int i = 0; i < 3; i++ ) {
		int status = 0;
		pid_t wait_return;
		
		if( pids[i] == pids[1] ) {
			wait_return = waitpid(pids[i], &status, WNOHANG);
		}else {
			wait_return = waitpid(pids[i], &status, 0);
		}
		
		
		if( wait_return > 0 && WIFEXITED(status) ) {
			int exit_status = WEXITSTATUS(status);
			printf("PID: %d Exit: %d\n", pids[exit_status - 1], exit_status);
		}
	}
	
	return 0;
}
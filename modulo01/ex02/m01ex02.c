#include <stdio.h>
#include<sys/types.h>
#include<unistd.h>
#include <sys/wait.h> 
#include <stdlib.h>

int main(void) {
	
	int n_filhos = 2;
	pid_t pid;
	pid_t pid_pai = getpid();
	int filhos[n_filhos];
	int count_terminados = 0;
	
	for(int i = 0; i < n_filhos; i++) {
		filhos[i] = fork();
		
		if(filhos[i] == 0) {
			switch (i) {
				case 0:
					printf("I am the first child.\n");
					break;
				case 1:
					printf("I am the second child.\n");
					break;
			}
			break;
		}
	}
	
	if (pid_pai == getpid()) {
		for(int i = 0; i < n_filhos; i++) {
			int status = 0;
			wait(&status);
			
			printf("Filho terminado com exit: %d\n", status);
		}
	} else {
		sleep(3);
		exit(count_terminados++);
	}
	
}
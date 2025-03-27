#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>

void M(char *);

int main() {
	pid_t pid_x;
	for( int i = 0; i < 2; i++) {
		pid_x = fork();
		
		if( pid_x > 0 ) {
			M("A");
			
		} else {
			M("B");
			pid_t pid_y = fork();
			
			if( pid_y > 0) {
				M("A");
				break;
			}
		}
	}
	
	return 0;
}

void M(char* print) {
	printf("%c\n", *print);
}
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <time.h>

int main() {
	const int size = 10;
	int data[size];
	int result[size];
	
	srand(time(NULL));
	
	for(int i = 0; i < size; i++) {
		data[i] = rand() % 10 + 1;
	}
	
	pid_t pid = fork();
	
	if(pid > 0) {
		
		for(int i = size / 2; i < size; i++) {
			result[i] = data[i]*4 + 20;
		}
		
		wait(NULL);
			
		for(int i = size / 2; i < size; i++){
			printf("result[%d]: %d\n",i ,result[i]);
		}
	} else {
		for(int i = 0; i < size / 2; i++) {
			result[i] = data[i]*4 + 20;
			printf("result[%d]: %d\n",i ,result[i]);
		}
		
	}
	
	
	return 0;
}
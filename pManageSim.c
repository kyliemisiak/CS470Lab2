// CS 470 - Lab 2
// Demonstrates the use of fork(), wait(), and exec


// Add necessary headers
#include <unistd.h>
#include <sys/wait.h>
#include <stdio.h>
#include <stdlib.h>

int main(){

	int pid;
	int i;

	for(i = 0; i < 10; i++){
		pid = fork();

		if(pid < 0){
			//if pid is less than 0, error
			perror("fork failed");
			exit(1);
		}else if(pid == 0){
			//pid == 0, create child process
			//argument array
			char *args[4];

			//start switch cases
			switch(i){
				case 0:
					//first task
					args[0] = "echo";
					args[1] = "Hello Kylianna";
					args[2] = NULL;
					execvp(args[0], args);
					break;
				case 1:
					//task 2
					args[0] = "ls";
					args[2] = NULL;
					execvp(args[0], args);
					break;
				case 2:
					//task 3
                    			args[0] = "echo";
                    			args[1] = "This is the third task";
                    			args[2] = NULL;
                    			execvp(args[0], args);
                    			break;
				case 3:
					//task 4
					args[0] = "echo";
                    			args[1] = "Fourth task.";
                    			args[2] = NULL;
                    			execvp(args[0], args);
                    			break;
				case 4:
					//task 5
					args[0] = "echo";
                    			args[1] = "Fifth Task.";
                    			args[2] = NULL;
                    			execvp(args[0], args);
                    			break;
				default:
					break;
			}
			perror("execvp failed");
			exit(1);
		}
	}

	for(i = 0; i < 10; i++){
		wait(NULL);
	}

	printf("All child processes have completed.\n");
	return 0;
}

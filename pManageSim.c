// CS 470 - Lab 2
// Demonstrates the use of fork(), wait(), and exec


// Add necessary headers
#include <unistd.h>
#include <sys/wait.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>

int main(){

	pid_t pid;
	int i;
	int status;

	//use fork() in a loop to create multiple child processes
	for(i = 1; i < 11; i++){
		pid = fork();

		//include basic error handling
		if(pid < 0){
			//if pid is less than 0, error
			perror("fork failed");
			exit(1);
		}else if(pid == 0){
			//pid == 0, create child process
			//argument array
			char *args[4];

			printf("Child %d with PID %d started.\n", i, getpid());

			//start switch cases for child tasks
			switch(i){
				case 0:
					//task 1
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
                    			args[1] = "This is the fourth task.";
                    			args[2] = NULL;
                    			execvp(args[0], args);
                    			break;
				case 4:
					//task 5
					args[0] = "echo";
                    			args[1] = "This is the fifth Task.";
                    			args[2] = NULL;
                    			execvp(args[0], args);
                    			break;
				case 5:
					//task 6
					args[0] = "echo";
					args[1] = "This is the sixth task";
					args[2] = NULL;
					execvp(args[0], args);
					break;
				case 6:
					//task 7
					args[0] = "echo";
					args[1] = "This is the seventh task";
					args[2] = NULL;
					execvp(args[0], args);
					break;
				case 7:
					//task 8
					args[0] = "echo";
					args[1] = "This is the eighth task";
					args[2] = NULL;
					execvp(args[0], args);
					break;
				case 8:
					//task 9
					args[0] = "echo";
					args[1] = "This is the ninth task";
					args[2] = NULL;
					execvp(args[0], args);
					break;
				case 9:
					//task 10
					args[0] = "echo";
					args[1] = "This is the last task, task 10";
					args[2] = NULL;
					execvp(args[0], args);
					break;
				default:
					break;
			}

		}else{
			pid_t wpid = waitpid(pid, &status, 0);

			if(wpid == -1){
				perror("waitpid failed");
			}else{

			//use wait() or waitpid() to wait for child processses to finish
			//report completion status of each child process
				if(WIFEXITED(status)){
					int exit_stat = WEXITSTATUS(status);
					printf("Child %d exited normally with status %d. \n", wpid, exit_stat);
				}else if(WIFSIGNALED(status)){
					int signal_num = WTERMSIG(status);
					printf("Child %d was terminated by signal %d.\n", wpid, signal_num);
				}else{
					printf("Child %d terminated abnormally.\n", wpid);
				}
			}
		}
	}
	printf("All child processes have completed.\n");
	return 0;
}

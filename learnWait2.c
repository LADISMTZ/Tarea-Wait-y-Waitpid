#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include <time.h>
#include <stdlib.h>


int main(){

pid_t pid_A, pid_B, pid_M;
int status;

pid_A = fork();
if (pid_A==0){

	sleep(10);
	printf("Mi pid es: %d\n", getpid());
	return 10;
	}

pid_B = fork();
if(pid_B==0){

	printf("Mi pid es: %d\n", getpid());
	return 0;
	
	}	
		
pid_M = fork();	
if(pid_M==0){

	sleep(3);
	printf("Mi pid es: %d\n", getpid());
	return 3;
	
	}


waitpid(pid_M, &status, 3);
printf("El valor de retorno de M es: %d\n",WEXITSTATUS(status));
waitpid(pid_A, &status, 10);
printf("El valor de retorno de A es: %d\n",WEXITSTATUS(status));
waitpid(pid_B, &status, 0);
printf("El valor de retorno de B es: %d\n",WEXITSTATUS(status));
}





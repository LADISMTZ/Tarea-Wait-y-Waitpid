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
int numAleatorio, numProcesos=0;
srand(time(NULL));
int status;

pid_A = fork();
if (pid_A==0){

	numAleatorio=rand();
	printf("Mi pid es: %d\n", getpid());
	printf("El numero random es: %d\n"), numAleatorio;
	return 0;
	}

pid_B = fork();
if(pid_B==0){

	numAleatorio=rand();
	printf("Mi pid es: %d\n", getpid());
	printf("El numero random es: %d\n"), numAleatorio;
	return 0;
	
	}	
		
pid_M = fork();	
if(pid_M==0){

	numAleatorio=rand();
	printf("Mi pid es: %d\n", getpid());
	printf("El numero random es: %d\n"), numAleatorio;
	return 0;
	
	}


wait(&status);
if (WEXITSTATUS(status)==0){
numProcesos++;
}
wait(&status);
if (WEXITSTATUS(status)==0){
numProcesos++;
}
wait(&status);
if (WEXITSTATUS(status)==0){
numProcesos++;
}
printf("Numero de procesos completados: %d\n", numProcesos);
}





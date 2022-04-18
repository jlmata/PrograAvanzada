#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main(){
	int pid;
	pid = fork();
	if(pid == 0){
		printf("hola mundo, pid:[%d]\n", getpid());
		pid = fork();
		if(pid == 0){
			printf("hijo 1, pid:[%d]\n", getpid());
			exit(0);
		}
		pid = fork();
		if(pid == 0){
			printf("hijo 1, pid:[%d]\n", getpid());
			exit(0);	
		}
		printf("Fin de pricesos hijos");
	}
	sleep(10);
}
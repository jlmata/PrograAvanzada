#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <pthread.h>

//espera la ejecución de la función el thread, en caso de que fuera un proceso se ejecutaria 

void *funcion(void *arg) {
	char *s = (char *)arg;

	printf("[%s] - Thread:[%ld]\n", s, (long)pthread_self());

	return 0;
}

int main(int argc, char *argv[]) {
	pthread_t t1;
	void *res;
	int s, i;

	for (i=0; i<5; i++) {
	   	s = pthread_create(&t1, NULL, funcion, "Hello world"); 
		if (s != 0) {
		        perror("pthread_create");
		        exit(-1);
		}
	}


	sleep(5);

	printf("About to exit\n");

	exit(0);
}
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <pthread.h>

void *funcion(void *arg) {
	char *s = (char *)arg;

	printf("%s", s);

	return (void *)strlen(s);
}

int main(int argc, char *argv[]) {
	pthread_t t1;
	void *res;
	int s;

   	s = pthread_create(&t1, NULL, funcion, "Hello world\n"); 
	if (s != 0) {
	        perror("pthread_create");
	        exit(-1);
	}

	printf("Message from main()\n");
	s = pthread_join(t1, &res);

	if (s != 0) {
		perror("pthread_join");
		exit(-1);
	}

	printf("Thread returned %ld\n", (long) res);

	exit(0);
}
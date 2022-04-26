#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <signal.h>
#include <time.h>

FILE *fp;
char buffer[64];

int daemonize() {
	if(fork()) exit (0);
	setsid();
}

char *prtime() {
	time_t rawtime;
	struct tm * timeinfo;

	time(&rawtime);
	timeinfo = localtime(&rawtime);
	strftime(buffer, 64, "%F %H:%M:%S", timeinfo);

	return buffer;
}

void handler_int(int sig) {
	fprintf(fp, "[%s] Recibi SIGINT\n", prtime());
	fflush(fp);
}

void handler_usr1(int sig) {
	fprintf(fp, "[%s] Recibi SIGUSR1, terminando\n", prtime());
	fflush(fp);
	exit(0);	
}



int main() {
	fp = fopen("salida.txt", "w");

	// Crea la funcion daemonize que convierta a este programa en un daemon
	daemonize();

	signal(SIGINT, handler_int);
	signal(SIGTERM, SIG_IGN);
	signal(SIGUSR1, handler_usr1);

	// Crea un handler para SIGINT que reciba la se;al y lo registre en el archivo
	// Crea un handler para SIGTERM que reciba la se;al y la ignore
	// Crea un handler para SIGUSR1 que reciba la se;al, lo registre en el archivo y termine

	while(1) {
		sleep(2);
		fprintf(fp, "[%s] Sigo vivo:[%d]\n", prtime(), getpid());
		fflush(fp);
	}
}
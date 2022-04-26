#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <signal.h>

// Guardar aqui los pid de los hijos
int pids[5];

// Handler para cada hijo
void handler(int sig) {
	printf("Soy el hijo:[%d], recibi se;al\n", getpid());
}

int main () {
	int pid, i;
	// Iniciar el motor de numeros aleatorios
	srandom(getpid());


	// Se deben de crear 5 hijos, se guardan sus pids en el arreglo
	// Para cada hijo, configurar el handler para la se;al SIGTERM
	// Luego dejar el proceso en while(pause())
	for(i=0; i<5; i++) {
		if ( !(pid=fork()) ) {
			signal(SIGTERM, handler);
			while(pause()); // NO es espera activa
		}
		pids[i] = pid;
	}


	// En un ciclo seleccionar uno de los procesos aleatorios y mandarle un SIGTERM
	// esto debe pasar cada segundo durante 10 segundos
	for(i=0; i<10; i++) {
		sleep(1);
		pid = pids[random()%5];
		// La imagen de x mod n es de 0 a n
		// aleatorio entre a y b:     random()%(b+1-a) + a

		printf("[%d] Enviando se;al al [%d]\n", getpid(), pid);
		kill(pid, SIGTERM);
	}

	// Recordar explicar qué es un zombie
	/* Un padre crea un proceso hijo:

	1) Si el padre termina y el hijo sigue corriendo, el init se convierte en el padre.
	   Esto se aprovecha en los procesos daemon.
	
	2) Si el hijo termina, el padre sigue corriendo Y el padre no ha hecho wait, 
	   el hijo se convierte en zombie y sigue ocupando recursos aunque ya termino.
	   Para liberar los recursos (memoria, archivos) o bien el padre termina o se hace 
           wait para que el SO reclame la memoria ocupada.
	 */
	
}

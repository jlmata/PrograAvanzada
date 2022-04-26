#include <stdio.h>
#include <signal.h>
#include <unistd.h>

/* 
   Crea una funcion para reaccionar al evento ctrl+c, cada vez que reciba la se;al
   debe imprimir un mensaje a la consola
 */
// Aqui la funcion
void handler(int sig) {
	printf("Recibi la señal:[%d]\n", getpid());
}

int main () {
	// Usando la syscall signal, configura el handler
	signal(SIGINT, handler);

	// la syscall pause bloquea al proceso hasta recibir una se;al,
	// en el ciclo lo hace una y otra vez
	while(pause());
	
}
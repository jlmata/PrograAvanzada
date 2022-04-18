#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

void char_por_char(char *p) {
    srandom(getpid());

    while(*p) {
        putc(*p, stdout);
	fflush(stdout);
        usleep(random()%100000);
        p++;
    }
}

int main () {
    printf("\n");

    if(!fork()) {
        char_por_char("Este es un mensaje algo largo desde el hijo\n");
        exit(0); 
    } else {
        wait(0); 
        char_por_char("Este es un mensaje algo largo desde el padre\n");
    }

}

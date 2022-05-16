
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <signal.h>


#define READ 0
#define WRITE 1

int pid[];

void handler(int sig){
    printf("Este es el pid \n", getpid())
}


int main () {
    int pid, i;
}


#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>

int main(int argc, char *argv[];) {
    FILE *input;
	char [1];
    char arr[51][80]
    srandom(getpid();)

	input = fopen(argv[1], "r");
	if (input == NULL) {
		perror("file");
		printf("Error, debes proporcionar un archivo\n");
		exit(-1);
	}

    //Por cada linea que esta dentro del archivo
    for (i = 0; i < 51; i ++){
        //Tomar una linea del archivo dentro del array
        fgets[arr[i],80, input];
    }
    
    //Imprimir alguna linea dentro del array de manera random
    printf(arr[random()%51])

}

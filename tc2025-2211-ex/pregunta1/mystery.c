#include <stdio.h>
#define I2S(x) ((short *) x)

int main() {
    int i, x[10];

    for(i=0; i<10; i++) {
        x[i] = i;
    }

    // ¿Por qué se imprimen alternados con 0 los numeros asignados en el for anterior?
    //El define I2S(x) ((short *) x)crea un macro que actua ante de que se compile
    for(i=0; i<10; i++) {
        printf("%d\n", *I2S(x+i));
    }
    
}

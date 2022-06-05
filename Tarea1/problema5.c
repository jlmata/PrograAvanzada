#include<stdio.h>

double calcularLeibniz(double iteraciones) {
    
    int signo = 1;
    double numerador = 4;
    double denominador = 1; 
    double pi = 0;
    int x = 0;
    
    for (x; x < iteraciones; x++) {
        pi += signo * (numerador / denominador);
        denominador += 2; 
        signo *= -1;   
    }
  
    return pi;
}

void main() {

    printf("1000: %f \n",calcularLeibniz(1000));
    printf("10000: %f \n",calcularLeibniz(10000));
    printf("1000000: %f \n",calcularLeibniz(100000));
    
    return 0;
}
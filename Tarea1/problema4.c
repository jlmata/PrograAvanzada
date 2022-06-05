#include <stdio.h>
#include <stdlib.h>
int a; //global
int b = 10; //global con valor

int main()
{   
    //Stack
    int c;
    int d = 10;
    //Array
    int arr[10];

    printf("Global: %lu\n", sizeof(a)); 
    printf("Global (inicializado): %lu\n", sizeof(b));     
    printf("Stack: %lu\n", sizeof(c));   
    printf("Stack (inicializado): %lu\n", sizeof(d));
    printf("Array: %lu\n", sizeof(arr));   
    
    return 0;
}
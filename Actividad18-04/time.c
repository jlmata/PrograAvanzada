#include <unistd.h>
#include <stdio.h>
#include <sys/wait.h>

int main(){
    int n = 5;
    while(n--){
        if(!fork()){
            execlp("date", "date", (char *)0); 

        }
        sleep(1); 
    }
    printf("el ls ha terminado \n")
}

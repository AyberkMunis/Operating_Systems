#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <signal.h>

void handle_signal(int signal){
    printf("Recieved Signal %d\n",signal);
}


int main(){
    signal(SIGINT,&handle_signal);
    int x;
    while(1){
        printf("main Hello!\n");
        sleep(1);
    }
}
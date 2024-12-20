#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <signal.h>
int x=0;
void signal_handler(int sig){
    if(x==0){
        printf("\nMultiplication is repetition of summation\n");

    }




}


int main(){

    int pid=fork();
    if(pid==0){
        sleep(5);
        kill(getppid(),SIGUSR1);
    }
    else{
        struct sigaction sa;
        sa.sa_handler=&signal_handler;
        sa.sa_flags=SA_RESTART;
        sigaction(SIGUSR1,&sa,NULL) ;//third parameter is restore sigaction struct if you used before
        printf("Input no: \n");
        scanf("%d",&x);
        printf("The number is %d",x);
        wait(NULL);
        
    }


}
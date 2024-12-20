#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <signal.h>

void handle_signal(int signal){
    printf("Not ALlowed\n");
}


int main(){
    struct sigaction sa;
    sa.sa_handler=&handle_signal;
    sa.sa_flags=SA_RESTART;
    sigaction(SIGTSTP,&sa,NULL) ;//third parameter is restore sigaction struct if you used before
    //signal(SGTSTP,&handle_signal)
    int x;
    printf("Input no: ");
    scanf("%d",&x);
    printf("The number is %d",x);
}
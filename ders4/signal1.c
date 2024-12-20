#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <signal.h>

int main(){
    int pid=fork();

    if(pid==0){
        while(1){
            printf("Ada Edu\n");
        }
    }
    else{
        sleep(1);
        kill(pid,SIGSTOP);
        printf("Child Process is stopped\n");
        sleep(1);
        printf("Child process starts to continue\n");
        sleep(1);
        kill(pid,SIGCONT);
        sleep(1);
        kill(pid,SIGKILL);
        wait(NULL);
        printf("Parent Process is terminated\n");
    }
}
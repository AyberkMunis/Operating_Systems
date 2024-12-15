#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
int main(){
    int id1=fork(); 
    int id2=fork();
    if(id1==0){
        if(id2==0){
            printf("Process y\n");
        }
        else{
            printf("Process X\n");
        }
    }
    else{
        if(id2==0){
            printf("Process z\n");
        }else{
            printf("Parent\n");
        }
    }
    //wait(NULL); only waites for 1 process
    while(wait(NULL)!=-1){
        printf("Child Process Terminated\n");
    }

    
    return 0;
}

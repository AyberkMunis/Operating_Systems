#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
int main(){
    int fd[2];
    //fd[0] for read
    //fd[1] for write
    if(pipe(fd)==-1){
        printf("There is an error");
        return 1;
    }
    //we are opening the pipe before to inherit it to both processes
    int id=fork();
    if(id==-1){
        printf("There is an error");
        return 2;
    }
    if(id==0){
        close(fd[0]);
        int a;
        printf("Write a number:");
        scanf("%d",&a);
        if(write(fd[1],&a,sizeof(int))==-1){
            printf("There is an error");
            return 4;
        }
        close(fd[1]);


    }
    else{
        close(fd[1]);
        int c;
        if(read(fd[0],&c,sizeof(int))==-1){
            printf("There is an error");
            return 3;
        }
        printf("Number from other process : %d",c);
        close(fd[0]);
    }

    
    return 0;
}

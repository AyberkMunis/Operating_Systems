#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
int main(){
    int fd[2];
    pipe(fd);
    int id=fork();
    if(id==0){
        int x;
        read(fd[0],&x,sizeof(int));
        printf("Recieved %d\n",x);
        x*=5;
        write(fd[1],&x,sizeof(int));
        
    }
    else{
        int x=6;
        int r;
        write(fd[1],&x,sizeof(int));
        printf("Sent %d\n",x);
        read(fd[0],&r,sizeof(int));
        printf("Final result: %d",r);

    }
    close(fd[0]);
    close(fd[1]);
    //solve the problem together by using 2 pipes
}
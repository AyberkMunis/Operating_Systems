#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
int main(){
    int id=fork(); 
    int n;
    if(id!=0){
        sleep(1);
    }
    printf("Parent Id: %d Current Id:%d\n",getppid(),getpid());
    int res=wait(NULL);
    if(res==-1){
        printf("Nothing to wait\n");
    }
    else{
        printf("%d process is finished\n",res);
    }

    
    return 0;
}

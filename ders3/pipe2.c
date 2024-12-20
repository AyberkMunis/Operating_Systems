#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
int main(){
    int fd[2];
    int arr[6]={1,2,3,4,5,6};
    int arrsize=sizeof(arr)/sizeof(int);
    if(pipe(fd)==-1){
        printf("There is an error");
        return 1;
    }
    int id=fork();
    int start;
    int end;
    if(id==0){
        start=0;
        end=arrsize/2;

    }
    else{
        start=arrsize/2;
        end=arrsize;
    }
    int sum=0;
    for(int i=start;i<end;i++){
        sum+=arr[i];
        
        
    }
    if(id==0){
        close(fd[0]);
        int sumtop=sum;
        write(fd[1],&sumtop,sizeof(int));
        close(fd[1]);
    }
    else{
        close(fd[1]);
        int sumfc;
        read(fd[0],&sumfc,sizeof(int));
        printf("Sum from child : %d\n",sumfc);
        int totalsum=sum+sumfc;
        printf("Sum from parent is %d\nTotal Sum is: %d",sum,totalsum);
    }



    
    return 0;
}

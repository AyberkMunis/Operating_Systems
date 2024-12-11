#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

int main(){
    int id=fork(); // Creates a child Process
    //If id=0 it is child process
    if(id==0){
        printf("Ada edu operating systems: %d\n",id);
        printf("Child Process\n");
    }
    else{
        printf("Ada edu operating systems: %d\n",id);
        printf("Parent Process\n");

    }
    
    return 0;
}

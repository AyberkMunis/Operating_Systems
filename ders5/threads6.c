#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <signal.h>
#include <threads.h>
#include <pthread.h>
//race conditions

int liste[10]={1,2,3,4,5,6,7,8,9,10};
void* threadf(void* arg){
    int index= *(int*)arg;
    printf("%d ",liste[index]);


}

int main(){
    pthread_t t1[10];
    for(int i=0;i<10;i++){
            int* a=malloc(sizeof(int));
            *a=i;
            if(pthread_create(t1+i,NULL,&threadf,a)!=0){
                printf("error");
                return -1;
            }
            if(pthread_join(t1[i],NULL)!=0){
                printf("Error");
                return -1;
            }
            free(a);
            

    }
    return 0;
}
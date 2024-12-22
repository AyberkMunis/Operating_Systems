#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <signal.h>
#include <threads.h>
#include <pthread.h>
//race conditions
int x=0;
pthread_mutex_t mutex;

void* threadf(){
    for(int i=0;i<10000000;i++){
        pthread_mutex_lock(&mutex);
        x++;
        pthread_mutex_unlock(&mutex);
    }
}

int main(){
    pthread_mutex_init(&mutex,NULL);
    pthread_t t1[4];
    for(int i=0;i<4;i++){
            if(pthread_create(t1+i,NULL,&threadf,NULL)!=0){
                printf("error");
                return -1;
            }
            if(pthread_join(t1[i],NULL)!=0){
                printf("Error");
                return -1;
            }
            printf("%d Thread finished its execution\n",i);

    }
    pthread_mutex_destroy(&mutex);
    printf("Result:%d",x);
    return 0;
}
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
    pthread_t t1,t2;
    pthread_create(&t1,NULL,&threadf,NULL);
    pthread_create(&t2,NULL,&threadf,NULL);
    pthread_join(t1,NULL);
    pthread_join(t2,NULL);
    printf("Result:%d",x);
    return 0;
}
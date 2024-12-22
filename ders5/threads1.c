#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <signal.h>
#include <threads.h>
#include <pthread.h>

void* threadf(){
    printf("Ders 5\n");
}

int main(){
    pthread_t t1,t2;
    pthread_create(&t1,NULL,&threadf,NULL);
    pthread_create(&t2,NULL,&threadf,NULL);
    pthread_join(t1,NULL);
    pthread_join(t2,NULL);
    return 0;
}
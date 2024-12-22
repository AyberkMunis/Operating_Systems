#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <signal.h>
#include <threads.h>
#include <pthread.h>

void* threadf(){
    int x=25;
    int* res=malloc(sizeof(int)); // we need to dynamically allocate the memory
    *res=x;
    printf("%p\n",&x);
    return (void*) res;
}

int main(){
    pthread_t t1,t2;
    int* result;
    pthread_create(&t1,NULL,&threadf,NULL);

    pthread_join(t1,(void**) &result);
    printf("%p\n",result);
    printf("%d\n",*result);
    return 0;
}
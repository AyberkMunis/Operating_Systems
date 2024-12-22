#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <signal.h>
#include <threads.h>
#include <pthread.h>
//race conditions
int liste[9]={1,2,3,4,5,6,7,8,9};
void* threadf(void* arg){
    int index= *(int*)arg;
    int result=0;
    for(int i=index;i<index+3;i++){
        result+=liste[i];

    }
    int* p=malloc(sizeof(int));
    *p=result;
    printf("%d\n",result);
    return (void*) p;


}

int main(){
    int x=0;
    pthread_t t1[10];
    for(int i=0;i<3;i++){
            int* a=malloc(sizeof(int));
            *a=i*3;
            int* y=0;
            if(pthread_create(t1+i,NULL,&threadf,a)!=0){
                printf("error");
                return -1;
            }
            if(pthread_join(t1[i],(void **)&y)!=0){
                printf("Error");
                return -1;
            }
            x+=*y;
            free(a);
            

    }
    printf("TOtal Result is %d",x);
    return 0;
}
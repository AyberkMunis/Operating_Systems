int main(){
    int fd[2]; //write P->C
    int fd2[2];// read C->P
    pipe(fd);
    pipe(fd2);
    int id=fork();
    if(id==0){
        close(fd[1]);
        close(fd2[0]);
        int x;
        read(fd[0],&x,sizeof(int));
        printf("Recieved %d\n",x);
        x*=5;
        write(fd2[1],&x,sizeof(int));
        
    }
    else{
        close(fd[0]);
        close(fd2[1]);
        int x=25;
        int r;
        write(fd[1],&x,sizeof(int));
        printf("Sent %d\n",x);
        read(fd2[0],&r,sizeof(int));
        printf("Final result: %d",r);

    }
    //solve the problem together by using 2 pipes
}
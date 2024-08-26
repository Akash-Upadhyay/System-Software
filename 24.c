#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>

void main(int argc,char *argv[]){
int pid = fork();
if(pid==0){
printf("PID of child process:%d\n",getpid());
sleep(5);
printf("Child process exiting...\n");
return;
}
else{
printf("PID of parent process:%d\n",getpid());
}
return ;
}


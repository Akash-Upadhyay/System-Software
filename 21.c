#include<stdio.h>
#include<unistd.h>


void main(){

int pid = fork();
if(pid==0){
printf("Pid of child process:%d\n",getpid());
}
else{
printf("Pid of parent process:%d\n",getpid());
printf("Pid of child process:%d\n",pid);
}
return;
}

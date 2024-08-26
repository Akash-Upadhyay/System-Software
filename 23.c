#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>

void main(int argc,char *argv[]){
int pid = fork();
if(pid==0){
return;
}
else{
getchar();
}
return ;
}


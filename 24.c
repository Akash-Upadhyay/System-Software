/*
============================================================================
Name : 24.c
Author : Akash Upadhyay
Description : Write a program to create an orphan process
Date: 31st Aug, 2024.
============================================================================
*/

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


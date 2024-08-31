/*
============================================================================
Name : 25.c
Author : Akash Upadhyay
Description : Write a program to create three child processes. The parent should wait for a particular child (use `waitpid` system call).
Date: 31st Aug, 2024.
============================================================================
*/

#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
#include <sys/types.h>
#include <sys/wait.h>


void main(int argc,char *argv[]){
int pid1 = fork();
if(pid1==0){
printf("PID of child process:%d\n",getpid());
sleep(5);
printf("Child process exiting...%d\n",getpid());
return;
}
int pid2 = fork();
if(pid2==0){
printf("PID of child process:%d\n",getpid());
sleep(10);
printf("Child process exiting...%d\n",getpid());
return;
}
int pid3 = fork();
if(pid3==0){
printf("PID of child process:%d\n",getpid());
sleep(5);
printf("Child process exiting...%d\n",getpid());
return;
}
else{
printf("PID of parent process:%d\n",getpid());
printf("Parent process wait for the second child with pid:%d\n", pid2);
waitpid(pid2, NULL, 0);
printf("Parent process exiting\n");
}
return;
}







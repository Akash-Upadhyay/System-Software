/*
============================================================================
Name : 21.c
Author : Akash Upadhyay
Description : Write a program, call fork and print the parent and child process id.
Date: 31st Aug, 2024.
============================================================================
*/


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


// administrator@administrator-Swift-SFG14-71:~/Desktop/ClassWork/System-Software$ ./a.out
// Pid of parent process:7753
// Pid of child process:7754
// Pid of child process:7754

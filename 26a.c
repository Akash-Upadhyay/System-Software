/*
============================================================================
Name : 26a.c
Author : Akash Upadhyay
Description : Write a program to execute an executable program. 
    1. Use some executable program 
    2. Pass some input to an executable program. (for example execute an executable of `$./a.out name`)
Date: 31st Aug, 2024.
============================================================================
*/



#include<unistd.h>
#include<stdio.h>

void main(){
    char * filename="./sample.out";
    execl(filename,filename,NULL);
    perror("Error calling Executable\n");
    return;
}


// administrator@administrator-Swift-SFG14-71:~/Desktop/ClassWork/System-Software$ ./a.out
// Executable call without argument

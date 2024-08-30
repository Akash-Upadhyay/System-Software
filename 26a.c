// 26. Write a program to execute an executable program.
// a. use some executable program
//AKASH UPADHYAY
//MT2024013



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

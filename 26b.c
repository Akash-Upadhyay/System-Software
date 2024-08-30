// 26. Write a program to execute an executable program.
// b.pass some input to an executable program. (for example execute an executable of $./a.out name)
//AKASH UPADHYAY
//MT2024013



#include<unistd.h>
#include<stdio.h>

void main(int argc, char* argv[]){
    char * filename="./sample.out";
    if(argc==1){
        printf("Pass argument for execution");
        return;
    }
    execl(filename,filename,argv[1],NULL);
    perror("Error calling Executable\n");
    return;
}

// administrator@administrator-Swift-SFG14-71:~/Desktop/ClassWork/System-Software$ ./a.out Hello World
// Executable call with argument


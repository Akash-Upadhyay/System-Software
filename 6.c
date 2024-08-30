/// Question 6: Write a program to take input from STDIN and display on STDOUT. Use only read/write system calls
//AKASH UPADHYAY
//MT2024013


#include <unistd.h>
#include<stdio.h>
#include<fcntl.h>

int main(){

char  buff[100];
int r = read(0,buff,10);
int w = write(1,buff,10);
if(r==-1||w==-1){
perror("Error while reading and writing");
}
else{
printf("Successfull");
}
return 0;
}

//administrator@administrator-Swift-SFG14-71:~/Desktop/ClassWork/System-Software$ ./a.out
//Welcome
//Welcome
//Successfull


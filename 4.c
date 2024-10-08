/*
============================================================================
Name : 4.c
Author : Akash Upadhyay
Description : Write a program to open an existing file with read write mode. Try O_EXCL flag also.
Date: 31st Aug, 2024.
============================================================================
*/

#include<stdio.h>
#include<fcntl.h>

void main(int argc, char* argv[]){
char * filename;
int fd;
if(argc!=2){
printf("Pass the file name as argument\n");
}
else{
filename = argv[1];
fd = open(filename,O_CREAT|O_EXCL,0644);
if(fd!=-1){
printf("File Opened Successfully with  after using EXCL flag %d\n",fd);
}
else{
perror("Error Opening File With O_EXCL flag");
}
fd = open(filename, O_RDWR);
if(fd!=-1){
printf("File Opened Successfully with  file descriptor value: %d\n",fd);
}
else{
perror("Error Opening File");
}
}
}

//administrator@administrator-Swift-SFG14-71:~/Desktop/ClassWork/System-Software$ ./a.out ./4.txt
//Error Opening File With O_EXCL flag: File exists
//File Opened Successfully with  file descriptor value: 3



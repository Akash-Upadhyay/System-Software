/*
============================================================================
Name : 22.c
Author : Akash Upadhyay
Description : Write a program, open a file, call fork, and then write to the file by both the child as well as the parent processes. Check output of the file
Date: 31st Aug, 2024.
============================================================================
*/

#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>

void main(int argc,char *argv[]){
if(argc!=2){
printf("Pass the file name as argument");
return;
}
fork();
char * filename = argv[1];
int fd = open(filename,O_RDWR);
if(fd==-1){
perror("Error Opening file");
return;
}
lseek(fd,0,SEEK_END);
char * buff = "Hello";
int w = write(fd,buff,5);
if(w==-1){
perror("Error Writing file");
}
return ;
}


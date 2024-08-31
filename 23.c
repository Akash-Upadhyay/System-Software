/*
============================================================================
Name : 23.c
Author : Akash Upadhyay
Description : Write a program to create a Zombie state of the running program
Date: 31st Aug, 2024.
============================================================================
*/


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




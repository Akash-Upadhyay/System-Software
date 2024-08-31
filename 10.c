/*
============================================================================
Name : 10.c
Author : Akash Upadhyay
Description : Write a program to open a file with read write mode, write 10 bytes, move the file pointer by 10 bytes (use lseek) and write again 10 bytes. 
    1. Check the return value of `lseek` 
    2. Open the file with `od` and check the empty spaces in between the data.
Date: 31st Aug, 2024.
============================================================================
*/


#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<time.h>


void main(int argc, char* argv[]){
  if(argc!=2){
  printf("Pass the file name as argument\n");
  return ;
  }
  char *filename = argv[1];
  int fd = open(filename,O_RDWR);
  if(fd==-1){
  perror("Error Opening file\n");
  return ;
  }
  char buff[10]="TestText..";
  int w=write(fd,buff,10);
  if(w==-1){
   perror("Error writing\n");
   return;
  }
  int off = lseek(fd,10,SEEK_CUR);
  if(off==-1){
   perror("Error Opening Pointer\n");
   return;
  }
  w=write(fd,buff,10);
  if(w==-1){
   perror("Error writing\n");
   return;
  }
  return; 
}





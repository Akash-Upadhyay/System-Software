/*
============================================================================
Name : 11_b.c
Author : Akash Upadhyay
Description : Write a program to open a file, duplicate the file descriptor and append the file with both the descriptors and check whether the file is updated properly or not.
			Use dup2
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
  int fd1 = open(filename,O_RDWR);
  if(fd1==-1){
  perror("Error Opening file\n");
  return ;
  }
  char buff[10]="TestText.1";
  int w=write(fd1,buff,10);
  if(w==-1){
   perror("Error writing\n");
   return;
  }
  int fd2 = dup2(fd1,10);
  int sf = lseek(fd2,10,SEEK_SET);
  if(fd2==-1){
  perror("Error Opening file\n");
  return;
  }
  
  char buff1[10]="TestText.2";
  w=write(fd2,buff1,10);
  if(w==-1){
   perror("Error writing\n");
   return;
  }
  return; 
}




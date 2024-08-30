// 12. Write a program to find out the opening mode of a file. Use fcntl.
// AKASH UPADHYAY
// MT2024013


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
  int mode =  fcntl(fd1,F_GETFL);
  if(mode==-1){
  perror("Error getting flags\n");
  }
  int openMode = mode & O_ACCMODE;
  if (openMode == O_RDONLY) {
        printf("File opened in read-only mode\n");
    } else if (openMode == O_WRONLY) {
        printf("File opened in write-only mode\n");
    } else if (openMode == O_RDWR) {
        printf("File opened in read-write mode\n");
    }
    
    return;

}

// administrator@administrator-Swift-SFG14-71:~/Desktop/ClassWork/System-Software$ ./a.out ./files/sample_file1
// File opened in read-write mode





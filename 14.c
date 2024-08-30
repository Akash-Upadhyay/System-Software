
// AKASH UPADHYAY
// MT2024013
// 14 Write a program to find the type of a file.
// a. Input should be taken from command line.
// b. program should be able to identify any type of a file.


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
  struct stat buf;
  int stat = lstat(filename,&buf);
  
    if(stat==-1){
      perror("Error getting stats\n");
      return;
      }
    int res = buf.st_mode & S_IFMT;
    switch (res) {
        case S_IFREG:  printf("Regular file\n");        break;
        case S_IFDIR:  printf("Directory\n");           break;
        case S_IFLNK:  printf("Symbolic link\n");       break;
        case S_IFCHR:  printf("Character device\n");    break;
        case S_IFBLK:  printf("Block device\n");        break;
        case S_IFIFO:  printf("FIFO/pipe\n");           break;
        case S_IFSOCK: printf("Socket\n");              break;
        default:       printf("Unknown file type\n");   break;
    }
    return;

}



// administrator@administrator-Swift-SFG14-71:~/Desktop/ClassWork/System-Software$ ./a.out ./files/1.txt
// Regular file

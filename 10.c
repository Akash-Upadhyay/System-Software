
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




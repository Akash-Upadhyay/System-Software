/// Question 7: Write a program to copy file1 into file2 ($cp file1 file2).
//AKASH UPADHYAY
//MT2024013




#include<unistd.h>
#include<stdio.h>
#include<fcntl.h>

void main(int argc, char* argv[]){
char * srcfilename;
char *destfilename;
int fd1,fd2;
char buff[100];
if(argc!=3){
printf("Pass the source and destinantion name as argument\n");
return;
}
else{

srcfilename = argv[1];
destfilename = argv[2];
fd1 = open(srcfilename,O_RDONLY);
if(fd1==-1){
perror("Error Opening Source File");
return ;
}
fd2 = open(destfilename,O_WRONLY|O_CREAT,0644);
if(fd2==-1){
perror("Error Opening Destination File");
return ;
}

while(1){
int r = read(fd1,buff,1);
if(r==0){break;}
if(r==-1){
perror("Error reading from Source");
return;
}
int w = write(fd2,buff,1);
if(w==-1){
perror("Error writing In Destination");
return;
}
}
}
printf("Successfull");
return;
}

// administrator@administrator-Swift-SFG14-71:~/Desktop/ClassWork/System-Software$ ./a.out ./files/1.txt  ./files/2.txt 
// Successfull
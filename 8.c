//8. Write a program to open a file in read only mode, read line by line and display each line as it is read.
//Close the file when end of file is reached


#include<unistd.h>
#include<stdio.h>
#include<fcntl.h>

void main(int argc, char* argv[]){
char * srcfilename;
int fd1;
char buff[100];
char str[100];
if(argc!=2){
printf("Pass the source file name as argument\n");
return;
}
else{

int count=0;
srcfilename = argv[1];
fd1 = open(srcfilename,O_RDONLY);
if(fd1==-1){
perror("Error Opening Source File");
return ;
}
while(1){
int r = read(fd1,buff,1);
if(r==-1){
perror("Error in reading file");
close(fd1);
return;
}
if(r==0){
break;
}
if(buff[0]!='\n'){
str[count++] = buff[0];
}
else{
str[count++] = buff[0];
int w = write(1,str,count);

if(w==-1){
perror("Error writing In Destination");
close(fd1);
return;
}
count =0;
sleep(1);
}
}
}

printf("Successfull\n");
close(fd1);
return;
}

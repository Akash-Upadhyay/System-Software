
#include <unistd.h>
#include<stdio.h>
#include<fcntl.h>

int main(){

char  buff[100];
int r = read(0,buff,10);
int w = write(1,buff,10);
if(r==-1||w==-1){
perror("Error while reading and writing");
}
else{
printf("Successfull");
}
return 0;
}

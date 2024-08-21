// Question : Write a program to create five new files with infinite loop. Execute the program in the background and check the file descriptor table at /proc/pid/fd.


#include<stdio.h>
#include<fcntl.h>

int main(){

while(1){
int fd1 = creat("./files/sample_file1", 0644);
int fd2 = creat("./files/sample_file1", 0644);
int fd3 = creat("./files/sample_file1", 0644);
int fd4 = creat("./files/sample_file1", 0644);
int fd5 = creat("./files/sample_file1", 0644);
}
return 0;
}


// run ls -l /proc/pid/fd to check file descriptor related to this process



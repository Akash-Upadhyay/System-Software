/*
============================================================================
Name : 16_a.c
Author : Akash Upadhyay
Description : Write a program to perform mandatory locking. 
    - Implement write lock 
Date: 31st Aug, 2024.
============================================================================
*/

#include<stdio.h>
#include <unistd.h>
#include <fcntl.h>     
#include <sys/types.h> 
#include <sys/stat.h> 


int main(int argc, char *argv[])
{

    char *filename;
    struct flock lock;
    int fd;

    if (argc != 2){
        printf("Pass the file name ");
        return 0;
       } 
    else
    {
        filename = argv[1];
        lock.l_type = F_RDLCK;    
        lock.l_whence = SEEK_SET;
        lock.l_start = 0;        
        lock.l_len = 0;
        lock.l_pid = getpid();
        fd = open(filename, O_RDONLY);
        if(fd==-1){
        perror("Error Opening file");
        return 1;
        }
        int status = fcntl(fd, F_SETLK, &lock);
        if(status==0){
        printf("File locked for reading");
        }
        else{
        perror("Error Locking File");
        }
        getchar();
        close(fd);
    }
    return 0;
}


// administrator@administrator-Swift-SFG14-71:~/Desktop/ClassWork/System-Software$ ./a.out ./files/sample_file1
// File locked for reading^C

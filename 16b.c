/*
Question: Write a program to perform mandatory locking. 
    - Implement write lock 
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
        printf("Pass the file name to be locked as the argument!");
        return 0;
       } 
    else
    {
        filename = argv[1];
        lock.l_type = F_WRLCK;    
        lock.l_whence = SEEK_SET;
        lock.l_start = 0;        
        lock.l_len = 0;
        lock.l_pid = getpid();
        fd = open(filename, O_RDWR);
        if(fd==-1){
        perror("Error Opening file");
        return 1;
        }
        int status = fcntl(fd, F_SETLK, &lock);
        if(status==0){
        printf("File locked for writing");
        }
        else{
        perror("Error Locking File");
        }
        close(fd);
    }
    return 0;
}

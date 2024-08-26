#include <sys/types.h> 
#include <sys/stat.h> 
#include <fcntl.h>     
#include <unistd.h>    
#include <stdio.h>     

void main()
{
    char *ticketFile = "./files/ticket-file.txt";
    int fd;
    ssize_t Bytes;
    int buffer;
    fd = open(ticketFile, O_CREAT | O_RDWR, S_IRWXU);
    if (fd== -1)
        perror("Error while opening the file!");
    else
    {
        buffer = 1;
        Bytes = write(fd, &buffer, sizeof(int));
        if (Bytes == -1)
            perror("Error while writing to ticket!");
        else
            printf("Your ticket number is %d\n", buffer);
    }
    close(fd);
}

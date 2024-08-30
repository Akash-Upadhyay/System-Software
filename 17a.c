// 17. Write a program to simulate online ticket reservation. Implement write lock
// Write a program to open a file, store a ticket number and exit. Write a separate program, to
// open the file, implement write lock, read the ticket number, increment the number and print
// the new ticket number then close the file.
//AKASH UPADHYAY
//MT2024013


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


// administrator@administrator-Swift-SFG14-71:~/Desktop/ClassWork/System-Software$ ./a.out
// Your ticket number is 1

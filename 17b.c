// Question : Write a program to simulate online ticket reservations. Implement a write lock.  Write a program to open a file, store a ticket number, and exit.  Write a separate program, to open the file,  implement write lock, read the ticket number, increment the number, and print the new ticket number then close the file

#include <sys/types.h> // Import for `open`, `lseek`
#include <sys/stat.h>  // Import for `open`
#include <fcntl.h>     // Import for `fcntl` & `open`
#include <unistd.h>    // Import for `write`, `lseek` & `fcntl`
#include <stdio.h>     // Import for `perror` & `printf`

void main()
{
    char *ticketFile = "./files/ticket-file.txt";
    int fd,status;
    ssize_t readBytes, writeBytes;
    off_t lseekOffset;
    int buffer;
    struct flock Lock;

    fd = open(ticketFile,O_RDWR);

    if (fd == -1)
        perror("Error while opening the file!");
    else
    {
        Lock.l_type = F_WRLCK;
        Lock.l_pid = getpid();
        Lock.l_whence = SEEK_SET;
        Lock.l_len = 0;
        Lock.l_start = 0;
        status = fcntl(fd, F_SETLKW, &Lock);
        if (status == -1)
            perror("Error while locking the ticket file!");
        else
        {
        readBytes = read(fd, &buffer, sizeof(int));
        if (readBytes == -1)
            perror("Error while reading ticket!");
        else
        {
            lseekOffset = lseek(fd,0,SEEK_SET);
            if (lseekOffset == -1)
                perror("Error while seeking!");
            else
            {
                buffer += 1;
                writeBytes = write(fd, &buffer, sizeof(int));
                printf("Your ticket number is: %d\n", buffer);
            }
        }
        Lock.l_type = F_UNLCK;
        status = fcntl(fd, F_SETLKW, &Lock);
        if (status == -1)
            perror("Error releasing lock!");
        else
            printf("Done!\n");
      }
      close(fd);
    }
    return;
}

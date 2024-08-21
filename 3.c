#include<stdio.h>
#include<fcntl.h>


void main(int argc, char *argv[])
{

    char *filename;
    int fd; // FD -> Success, -1 -> Failure

    if (argc != 2)
        printf("Pass the file to be created as the argument\n");
    else
    {
        filename = argv[1];

        fd = creat(filename, 0644);

        if (fd == -1)
            perror("Error while creating the file!");
        else
            printf("The file was successfully created with the file descriptor -> %d\n", fd);
    }
}

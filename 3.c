//Q 3.Write a program to create a file and print the file descriptor value. Use creat ( ) system call
//AKASH UPADHYAY
//MT2024013



#include<stdio.h>
#include<fcntl.h>


void main(int argc, char *argv[])
{
    char *filename;
    int fd;
    if (argc != 2)
        printf("Pass the file name as argument\n");
    else
    {
        filename = argv[1];
        fd = creat(filename, 0644);
        if (fd == -1)
            perror("Error creating the file!");
        else
            printf("The file was successfully created\n");
    }
}

//administrator@administrator-Swift-SFG14-71:~/Desktop/ClassWork/System-Software$ ./a.out ./4.txt
//The file was successfully created


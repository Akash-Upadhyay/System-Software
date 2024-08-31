

/*
============================================================================
Name : 30.c
Author : Akash Upadhyay
Description : Write a program to run a script at a specific time using a Daemon process
Date: 31st Aug, 2024.
============================================================================
*/




#include<unistd.h>
#include<stdio.h>
#include<sys/stat.h>
#include<stdlib.h>
int main()
{
    if(!fork())
    {
        setsid();
        chdir("/");
        umask(0);
        while(1)
        {
            sleep(4);
            printf("child process=%d\n",getpid());
            printf("Daemon process is running\n");
        }
    }
    else
    exit(0);
}

// administrator@administrator-Swift-SFG14-71:~/Desktop/ClassWork/System-Software$ child process=14219
// Daemon process is running
// child process=14219
// Daemon process is running
// child process=14219
// Daemon process is running
// ^C
// administrator@administrator-Swift-SFG14-71:~/Desktop/ClassWork/System-Software$ child process=14219
// Daemon process is running
// child process=14219
// Daemon process is running
// child process=14219
// Daemon process is running
// child process=14219
// Daemon process is running
// ^C



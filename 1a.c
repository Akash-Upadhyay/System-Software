/*
============================================================================
Name : 1a.c
Author : Akash Upadhyay
Description : Create a soft link file using the `symlink` system call
Date: 31st Aug, 2024.
============================================================================
*/



#include <stdio.h>
#include <unistd.h>

int main() {
    int status = symlink("./files/1.txt", "./files/soft_link");
    if (status == 0) {
        printf("Successful\n");
    } else {
        perror("Not Successful");
    }
    return 0;
}



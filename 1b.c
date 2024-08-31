/*
============================================================================
Name : 1b.c
Author : Akash Upadhyay
Description : Create a hard link file using the `link` system call
Date: 31st Aug, 2024.
============================================================================
*/

#include <stdio.h>
#include <unistd.h>

int main() {
    int status = link("./files/1.txt", "./files/hard_link");
    if (status == 0) {
        printf("Successful\n");
    } else {
        perror("Not Successful");
    }
    return 0;
}



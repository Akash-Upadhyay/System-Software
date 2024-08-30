//AKASH UPADHYAY
//MT2024013
//Create the following types of a files using (i) shell command (ii) system call
//hard link (link system call)

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



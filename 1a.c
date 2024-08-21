#include <stdio.h>
#include <unistd.h>

int main() {
    // Create a symbolic link
    int status = symlink("./files/1.txt", "./files/soft_link");
    
    // Check if the symlink was created successfully
    if (status == 0) {
        printf("Successful\n");
    } else {
        perror("Not Successful");
    }
    
    return 0;
}


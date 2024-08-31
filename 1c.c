/*
============================================================================
Name : 1c.c
Author : Akash Upadhyay
Description : Create a FIFO file using the `mkfifo` library function or `mknod` system call
Date: 31st Aug, 2024.
============================================================================
*/

#include<sys/types.h> 
#include<sys/stat.h>  
#include<stdio.h>   

int main(int argc, char *argv[]){
	if(argc != 2){
		printf("Enter file name to create FIFO\n");
		return 0;
	}	
	const char *filename = argv[1];

	int mkfifo_status = mkfifo(filename, S_IRWXU);
	
	if(mkfifo_status == -1){
		perror("Error while creating FIFO file with mkfifo\n");
	}else{
		printf("Created FIFO file with mkfifo successfully\n");
	}
    return 0;
}

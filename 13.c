/*
============================================================================
Name : 13.c
Author : Akash Upadhyay
Description : Write a program to wait for a STDIN for 10 seconds using select. Write a proper print statement to verify whether the data is available within 10 seconds or not (check in $man 2 select).
Date: 31st Aug, 2024.
============================================================================
*/


#include <sys/time.h>  
#include <sys/types.h> 
#include <unistd.h>  
#include <stdio.h>   

int main(int argc, char *argv[]){
	fd_set readFDSet, writeFDSet;
	FD_SET(STDIN_FILENO,&readFDSet);
	FD_SET(STDOUT_FILENO,&writeFDSet);

	struct timeval time;
	time.tv_sec = 10;
	time.tv_usec = 0;

	int returnVal;
	returnVal = select(STDIN_FILENO+1,&readFDSet,&writeFDSet,NULL,&time);

	if(returnVal == -1){
		perror("ERROR\n");
	}else if(returnVal == 0){
		printf("No data was given for 10 seconds\n");
	}else{
		printf("The data is now available\n");
	}
	return 0;
}


// administrator@administrator-Swift-SFG14-71:~/Desktop/ClassWork/System-Software$ ./a.out
// No data was given for 10 seconds

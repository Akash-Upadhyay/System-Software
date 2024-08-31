/*
============================================================================
Name : 18.c
Author : Akash Upadhyay
Description : Question: Write a program to perform Record locking. 
    1. Implement write lock 
    2. Implement read lock
    Create three records in a file. Whenever you access a particular record, first lock it then modify/access to avoid race condition.
Date: 31st Aug, 2024.
============================================================================
*/


#include <sys/types.h> 
#include <sys/stat.h>  
#include <fcntl.h>    
#include <unistd.h>    
#include <stdio.h>     

#define RECORD_COUNT 3
#define RECORD_SIZE sizeof(struct record)

struct record {
    int recordNumber;
    int someNumber;
};

void initialize_records(int fd) {
    struct record records[RECORD_COUNT] = {
        {1, 0},
        {2, 0},
        {3, 0}
    };
    lseek(fd, 0, SEEK_SET);
    write(fd, records, RECORD_SIZE*RECORD_COUNT);
}

void lock_record(int fd, off_t record_offset) {
    struct flock lock;
    lock.l_type = F_WRLCK;
    lock.l_whence = SEEK_SET;
    lock.l_start = record_offset;
    lock.l_len = RECORD_SIZE;
    lock.l_pid = getpid();

    if (fcntl(fd, F_SETLKW, &lock) == -1) {
        perror("Error while locking record");
        _exit(1);
    }
}

void unlock_record(int fd, off_t record_offset) {
    struct flock lock;
    lock.l_type = F_UNLCK;
    lock.l_whence = SEEK_SET;
    lock.l_start = record_offset;
    lock.l_len = RECORD_SIZE;
    lock.l_pid = getpid();

    if (fcntl(fd, F_SETLKW, &lock) == -1) {
        perror("Error while unlocking record");
        _exit(1);
    }
}

int main() {
    char *filePath = "./files/18-file.txt";
    int fd = open(filePath, O_CREAT | O_RDWR, S_IRWXU);
    if (fd == -1) {
        perror("Error while opening the file");
        return 1;
    }
    if (lseek(fd, 0, SEEK_END) == 0) {
        initialize_records(fd);
    }
    struct record r;
    // for (int i = 0; i < RECORD_COUNT; ++i) {
    //     off_t record_offset = i * RECORD_SIZE;
    //     lock_record(fd, record_offset);
    //     lseek(fd, record_offset, SEEK_SET);
    //     read(fd, &r, RECORD_SIZE);
    //     printf("Record %d: Number=%d\n", r.recordNumber, r.someNumber);
    //     unlock_record(fd, record_offset);
    // }
    int i;
    printf("\n Enter the record no you want to increment:");
    scanf("%d",&i);
    getchar();
    i--;
   
        off_t record_offset = i * RECORD_SIZE;
        lock_record(fd, record_offset);
        lseek(fd, record_offset, SEEK_SET);
        read(fd, &r, RECORD_SIZE);
       // printf("Record %d: Number=%d\n", r.recordNumber, r.someNumber);
        r.someNumber += 1;
        lseek(fd, record_offset, SEEK_SET);
        write(fd, &r, RECORD_SIZE);
        printf("Waiting for keyboard interrupt");
        getchar();
        unlock_record(fd, record_offset);
    

    printf("\n Updated Records are:\n");
    for (int i = 0; i < RECORD_COUNT; ++i) {
        off_t record_offset = i * RECORD_SIZE;
        lock_record(fd, record_offset);
        lseek(fd, record_offset, SEEK_SET);
        read(fd, &r, RECORD_SIZE);
        printf("Record %d: Number=%d\n", r.recordNumber, r.someNumber);
        unlock_record(fd, record_offset);
    }
    return 0;
}




//Demonstration of record locking
//Terminal 1--
// administrator@administrator-Swift-SFG14-71:~/Desktop/ClassWork/System-Software$ ./a.out

//  Enter the record no you want to increment:1
// Waiting for keyboard interrupt

//Terminal 2--
// administrator@administrator-Swift-SFG14-71:~/Desktop/ClassWork/System-Software$ ./a.out

//  Enter the record no you want to increment:2
// Waiting for keyboard interrupt

//ABLE TO UPDATE PARALLELY ON BOTH RECORDS




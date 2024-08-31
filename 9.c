
/*
============================================================================
Name : 9.c
Author : Akash Upadhyay
Description : Write a program to print the following information about a given file - 
    1. Inode 
    2. Number of hard links 
    3. UID 
    4. GID 
    5. Size 
    6. Block size 
    7. Number of blocks 
    8. Time of last access 
    9. Time of last modification 
    10. Time of last change
Date: 31st Aug, 2024.
============================================================================
*/

#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<time.h>


void main(int argc, char* argv[]){
  if(argc!=2){
  printf("Pass the file name as argument\n");
  return ;
  }
  char *filename = argv[1];
  int fd = open(filename,O_RDWR);
  if(fd==-1){
  perror("Error Opening file\n");
  return ;
  }
  struct stat fileStat;
  int s = stat(filename,&fileStat);
  if(s==-1){
  perror("Error getting file information");
  return ;
  }
  printf("File: %s\n", argv[1]);
  printf("  Inode Number: %ld\n", (long)fileStat.st_ino);
  printf("  Number of Hard Links: %ld\n", (long)fileStat.st_nlink);
  printf("  User ID (UID): %u\n", fileStat.st_uid);
  printf("  Group ID (GID): %u\n", fileStat.st_gid);
  printf("  Size: %ld bytes\n", (long)fileStat.st_size);
  printf("  Block Size: %ld bytes\n", (long)fileStat.st_blksize);
  printf("  Number of Blocks: %ld\n", (long)fileStat.st_blocks);
  printf("  Time of Last Access: %s", ctime(&fileStat.st_atime));
  printf("  Time of Last Modification: %s", ctime(&fileStat.st_mtime));
  printf("  Time of Last Status Change: %s", ctime(&fileStat.st_ctime));
  return ;
  
}



// administrator@administrator-Swift-SFG14-71:~/Desktop/ClassWork/System-Software$ ./a.out 9.c
// File: 9.c
//   Inode Number: 9460531
//   Number of Hard Links: 1
//   User ID (UID): 1000
//   Group ID (GID): 1000
//   Size: 2009 bytes
//   Block Size: 4096 bytes
//   Number of Blocks: 8
//   Time of Last Access: Sat Aug 31 00:06:46 2024
//   Time of Last Modification: Wed Aug 21 19:17:07 2024
//   Time of Last Status Change: Wed Aug 21 19:17:07 2024


// struct stat {
//     dev_t     st_dev;     // Device ID of the file
//     ino_t     st_ino;     // Inode number
//     mode_t    st_mode;    // File type and mode
//     nlink_t   st_nlink;   // Number of hard links
//     uid_t     st_uid;     // User ID of the file owner
//     gid_t     st_gid;     // Group ID of the file owner
//     dev_t     st_rdev;    // Device ID (if special file)
//     off_t     st_size;    // Total size of the file in bytes
//     blkcnt_t  st_blocks;  // Number of 512-byte blocks allocated
//     blksize_t st_blksize; // Block size for filesystem I/O
//     time_t    st_atime;   // Time of last access
//     time_t    st_mtime;   // Time of last modification
//     time_t    st_ctime;   // Time of last status change
// };


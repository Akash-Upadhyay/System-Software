
// 27. Write a program to execute ls -Rl by the following system calls
// a. execl
// b. execlp
// c. execle.
// d. execv
// e. execvp

//AKASH UPADHYAY
//MT2024013

#include <unistd.h>
#include <stdio.h>

int main() {
    char *argv[] = {"ls", "-R","-l",NULL};
    execvp("ls", argv);
    perror("Error calling execv");
    return 0;
}


// administrator@administrator-Swift-SFG14-71:~/Desktop/ClassWork/System-Software$ gcc 27e.c
// administrator@administrator-Swift-SFG14-71:~/Desktop/ClassWork/System-Software$ ./a.out
// .:
// total 172
// -rw-rw-r-- 1 administrator administrator   963 Aug 30 19:14 10.c
// -rw-rw-r-- 1 administrator administrator   945 Aug 30 19:18 11a.c
// -rw-rw-r-- 1 administrator administrator   949 Aug 30 19:18 11b.c
// -rw-rw-r-- 1 administrator administrator   961 Aug 30 19:19 11c.c
// -rw-rw-r-- 1 administrator administrator  1024 Aug 30 19:21 12.c
// -rw-rw-r-- 1 administrator administrator  1476 Aug 30 20:01 14.c
// -rw-rw-r-- 1 administrator administrator  3844 Aug 30 19:26 15.c
// -rw-rw-r-- 1 administrator administrator  1131 Aug 30 19:34 16a.c
// -rw-rw-r-- 1 administrator administrator  1287 Aug 30 19:38 16b.c
// -rw-rw-r-- 1 administrator administrator  1079 Aug 30 19:40 17a.c
// -rw-rw-r-- 1 administrator administrator  2088 Aug 30 19:42 17b.c
// -rw-rw-r-- 1 administrator administrator     0 Aug 27 00:50 18.c
// -rw-rw-r-- 1 administrator administrator   335 Aug 20 10:20 1a.c
// -rw-rw-r-- 1 administrator administrator   382 Aug 30 18:47 1b.c
// -rw-rw-r-- 1 administrator administrator   524 Aug 30 19:44 21.c
// -rw-rw-r-- 1 administrator administrator   582 Aug 30 19:48 22.c
// -rw-rw-r-- 1 administrator administrator   264 Aug 30 19:54 23.c
// -rw-rw-r-- 1 administrator administrator   376 Aug 30 19:54 24.c
// -rw-rw-r-- 1 administrator administrator   940 Aug 30 19:57 25.c
// -rw-rw-r-- 1 administrator administrator   430 Aug 30 22:00 26a.c
// -rw-rw-r-- 1 administrator administrator   621 Aug 30 22:03 26b.c
// -rw-rw-r-- 1 administrator administrator  3686 Aug 30 22:24 27a.c
// -rw-rw-r-- 1 administrator administrator  3726 Aug 30 22:24 27b.c
// -rw-rw-r-- 1 administrator administrator  3840 Aug 30 22:24 27c.c
// -rw-rw-r-- 1 administrator administrator  3977 Aug 30 22:24 27d.c
// -rw-rw-r-- 1 administrator administrator   337 Aug 30 22:25 27e.c
// -rw-rw-r-- 1 administrator administrator   291 Aug 30 18:48 2.c
// -rw-rw-r-- 1 administrator administrator   676 Aug 30 18:53 3.c
// -rw-rw-r-- 1 administrator administrator   853 Aug 30 18:55 4.c
// -rw-rw-r-- 1 administrator administrator   585 Aug 30 18:56 5.c
// -rw-rw-r-- 1 administrator administrator   514 Aug 30 19:00 6.c
// -rw-rw-r-- 1 administrator administrator   991 Aug 30 19:03 7.c
// -rw-rw-r-- 1 administrator administrator  1644 Aug 30 21:51 8.c
// -rw-rw-r-- 1 administrator administrator  2495 Aug 30 19:10 9.c
// -rwxrwxr-x 1 administrator administrator 16056 Aug 30 22:25 a.out
// drwxrwxr-x 2 administrator administrator  4096 Aug 30 18:57 files
// -rw-rw-r-- 1 administrator administrator   210 Aug 30 21:58 sample.c
// -rwxrwxr-x 1 administrator administrator 15960 Aug 30 21:59 sample.out

// ./files:
// total 20
// -rwxrwxrwx 1 administrator administrator   0 Aug 30 22:14 1.txt
// -rw-r--r-- 1 administrator administrator  30 Aug 30 19:13 2.txt
// -rw-rw-r-- 1 administrator administrator  10 Aug 27 01:20 3.txt
// -rw-r--r-- 1 administrator administrator   0 Aug 30 18:50 4.txt
// -rw-r--r-- 1 administrator administrator 556 Aug 21 18:12 copied.c
// -rw-r--r-- 1 administrator administrator  30 Aug 30 19:47 sample_file1
// -rw-r--r-- 1 administrator administrator   0 Aug 30 18:57 sample_file2
// -rw-r--r-- 1 administrator administrator   0 Aug 30 18:57 sample_file3
// -rw-r--r-- 1 administrator administrator   0 Aug 30 18:57 sample_file4
// -rw-r--r-- 1 administrator administrator   0 Aug 30 18:57 sample_file5
// lrwxrwxrwx 1 administrator administrator  13 Aug 30 18:42 soft_link -> ./files/1.txt
// -rwx------ 1 administrator administrator   4 Aug 30 19:40 ticket-file.txt

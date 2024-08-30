
//19. Write a program to find out time taken to execute getpid system call. Use time stamp counter.
//AKASH UPADHYAY
//MT2024013


#include <sys/time.h>  
#include <sys/types.h> 
#include <unistd.h>   
#include <stdio.h>  

// Import for __rdtsc()
#ifdef _MSC_VER
#include <intrin.h>
#else
#include <x86intrin.h>
#endif

void main()
{
    int start, end, pid;
    struct timeval timestamp;

    start = __rdtsc();
    pid = getpid();
    end = __rdtsc();

    printf("PID: %d\n", pid);
    printf("Time taken : %d \n", (end - start));
}

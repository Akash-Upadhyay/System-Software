

// 28. Write a program to get maximum and minimum real time priority.

//AKASH UPADHYAY
//MT2024013



#include <stdio.h>
#include <sched.h>
#include <errno.h>

int main() {
    int p;
    p = sched_get_priority_min(SCHED_FIFO);
    if (p == -1) {
        perror("sched_get_priority_min");
        return 0;
    }
    printf("Minimum real-time priority: %d\n", p);
    p = sched_get_priority_max(SCHED_FIFO);
    if (p == -1) {
        perror("sched_get_priority_max");
        return 1;
    }
    printf("Maximum real-time priority: %d\n", p);
    return 0;
}


// administrator@administrator-Swift-SFG14-71:~/Desktop/ClassWork/System-Software$ ./a.out
// Minimum real-time priority: 1
// Maximum real-time priority: 99







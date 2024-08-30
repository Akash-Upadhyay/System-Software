


//29. Write a program to get scheduling policy and modify the scheduling policy (SCHED_FIFO,SCHED_RR).

//AKASH UPADHYAY
//MT2024013



#include <stdio.h>
#include <sched.h>
#include <stdlib.h>
#include <errno.h>
#include <unistd.h>

void print_policy(int policy) {
    switch (policy) {
        case SCHED_FIFO:
            printf("Current scheduling policy: SCHED_FIFO\n");
            break;
        case SCHED_RR:
            printf("Current scheduling policy: SCHED_RR\n");
            break;
        case SCHED_OTHER:
            printf("Current scheduling policy: SCHED_OTHER\n");
            break;
        default:
            printf("Unknown scheduling policy\n");
    }
}

int main() {
    int policy;
    struct sched_param param;

    policy = sched_getscheduler(0);
    if (policy == -1) {
        perror("sched_getscheduler");
        return 1;
    }
    
    print_policy(policy);

    param.sched_priority = 10;
    if (sched_setscheduler(0, SCHED_FIFO, &param) == -1) {
        perror("sched_setscheduler (SCHED_FIFO)");
        return 1;
    }

    policy = sched_getscheduler(0);
    if (policy == -1) {
        perror("sched_getscheduler");
        return 1;
    }
   
    switch (policy) {
        case SCHED_FIFO:
            printf("Current scheduling policy: SCHED_FIFO\n");
            break;
        case SCHED_RR:
            printf("Current scheduling policy: SCHED_RR\n");
            break;
        case SCHED_OTHER:
            printf("Current scheduling policy: SCHED_OTHER\n");
            break;
        default:
            printf("Unknown scheduling policy\n");
    }
    
   
    param.sched_priority = 20; 
    if (sched_setscheduler(0, SCHED_RR, &param) == -1) {
        perror("sched_setscheduler (SCHED_RR)");
        return 1;
    }

    policy = sched_getscheduler(0);
    if (policy == -1) {
        perror("sched_getscheduler");
        return 1;
    }
    
    switch (policy) {
        case SCHED_FIFO:
            printf("Current scheduling policy: SCHED_FIFO\n");
            break;
        case SCHED_RR:
            printf("Current scheduling policy: SCHED_RR\n");
            break;
        case SCHED_OTHER:
            printf("Current scheduling policy: SCHED_OTHER\n");
            break;
        default:
            printf("Unknown scheduling policy\n");
    }

    return 0;
}


// administrator@administrator-Swift-SFG14-71:~/Desktop/ClassWork/System-Software$ sudo ./a.out
// [sudo] password for administrator: 
// Current scheduling policy: SCHED_OTHER
// Current scheduling policy: SCHED_FIFO
// Current scheduling policy: SCHED_RR


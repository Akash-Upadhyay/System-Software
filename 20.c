
//20. Find out the priority of your running program. Modify the priority with nice command.

//AKASH UPADHYAY
//MT2024013


#include <stdio.h>
#include <sys/resource.h>
#include <unistd.h>

int main() {
    int priority = getpriority(PRIO_PROCESS, 0);
    if (priority == -1) {
        perror("getpriority");
        return 1;
    }
    printf("Current priority: %d\n", priority);
    return 0;
}

// administrator@administrator-Swift-SFG14-71:~/Desktop/ClassWork/System-Software$ ./a.out
// Current priority: 0
// administrator@administrator-Swift-SFG14-71:~/Desktop/ClassWork/System-Software$ nice -n 10 ./a.out
// Current priority: 10
// administrator@administrator-Swift-SFG14-71:~/Desktop/ClassWork/System-Software$ nice -n 15 ./a.out
// Current priority: 15


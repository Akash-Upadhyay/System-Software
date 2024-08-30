#include<stdio.h>

int main(int argc,char*argv[]){
    if(argc==1){
        printf("Executable call without argument\n");
    }
    else{
        printf("Executable call with argument\n");
    }
    return 0;
}
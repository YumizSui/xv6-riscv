#include "kernel/types.h"
#include "user/user.h" 

int main(void) {
    int start,end;
    start = gettime();
    sleep(50); // 5s
    end = gettime();

    printf("%d sec\n", end-start);
    exit(0);
}
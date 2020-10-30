#include "kernel/types.h"
#include "kernel/time.h"
#include "user/user.h" 

int main(void) {
    struct timeval start_tv,end_tv;
    gettime(&start_tv);
    sleep(57); // 5.7s
    gettime(&end_tv);
    int sec = end_tv.tv_sec-start_tv.tv_sec;
    int msec = (end_tv.tv_msec-start_tv.tv_msec);
    printf("%d.%d sec\n", sec, msec);
    exit(0);
}
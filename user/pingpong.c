// pingpong.c for xv6 (assignment #1 for CSC.T371)
// name: Kairi, FURUI
// id: 18B17230

#include "kernel/types.h"
#include "kernel/stat.h"
#include "user/user.h"

// <<<remove this comment and fill your code here if needed>>>

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(1, "usage: %s N\n", argv[0]);
        exit(1);
    }

    // # of rounds
    int n = atoi(argv[1]);
    // tick value before starting rounds
    int start_tick = uptime();
    // <<<remove this comment and fill your code here>>>
    int fd_p2c[2],fd_c2p[2];
    unsigned char buf=0;
    int round = 0;
    pipe(fd_p2c);
    pipe(fd_c2p);
    if(fork()==0){ // child
        close(fd_p2c[1]);
        close(fd_c2p[0]);
        while(round < n){
            if(read(fd_p2c[0], &buf, 1) == -1)exit(1);
            ++buf;
            // printf("%d\n", buf);
            if(write(fd_c2p[1], &buf, 1) == -1)exit(1);
            ++round;
        }
        exit(0);
    }else{ //parent
        close(fd_p2c[0]);
        close(fd_c2p[1]);
        while(round < n){
            // printf("%d\n", buf);
            if(write(fd_p2c[1], &buf, 1) == -1)exit(1);
            if(read(fd_c2p[0], &buf, 1) == -1)exit(1);
            ++buf;
            ++round;
        }
        // printf("%d\n", round);
        if(wait(0) == -1) exit(1);
    }

    
    // print # of ticks in nrounds
    printf("# of ticks in %d rounds: %d\n", n, uptime() - start_tick);
    exit(0);
}

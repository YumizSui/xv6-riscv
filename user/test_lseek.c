#include "kernel/types.h"
#include "kernel/stat.h"
#include "kernel/fcntl.h"
#include "kernel/fseek.h"
#include "user/user.h"

int main() {
    int fd = open("test.txt", O_WRONLY | O_CREATE | O_TRUNC);
    int off;
    // test1
    off = lseek(fd, 200, SEEK_SET);
    printf("test1: %d\n", off);

    // test2
    off = lseek(fd, 200, SEEK_SET);
    printf("test2: %d\n", off);
    
    // test3
    off = lseek(fd, -200, SEEK_CUR);
    printf("test3: %d\n", off);
    
    // test4
    off = lseek(fd, 0, SEEK_CUR);
    printf("test4: %d\n", off);

    // test5
    off = lseek(fd, 0, SEEK_END);
    printf("test5: %d\n", off);

    // test6
    off = lseek(fd, 100, SEEK_END);
    printf("test6: %d\n", off);

    close(fd);
    exit(0);
}

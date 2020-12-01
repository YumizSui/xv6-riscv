#include "kernel/types.h"
#include "kernel/stat.h"
#include "kernel/fcntl.h"
#include "kernel/fseek.h"
#include "user/user.h"

int main() {
    int fd;
    fd = open("foo.txt", O_WRONLY | O_CREATE | O_TRUNC);
    write(fd, "Hello World!", 13);
    close(fd);

    char buf1[64];
    fd = open("foo.txt", O_RDONLY);
    read(fd, buf1, 64);
    close(fd);
    printf("foo.txt:\n");
    printf("%s (expect Hello World!)\n", buf1);

    symlink("foo.txt", "bar.txt");
    printf("symlink foo.txt bar.txt\n");

    char buf2[64];
    fd = open("bar.txt", O_RDONLY);
    read(fd, buf2, 64);
    close(fd);
    printf("bar.txt:\n");
    printf("%s (expect Hello World!)\n", buf2);

    char buf3[64];
    readlink("bar.txt", buf3, 64);
    printf("readlink bar.txt\n");
    printf("%s (expect foo.txt)\n", buf3);
    exit(0);
}

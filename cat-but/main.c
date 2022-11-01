#include<unistd.h>
#include<sys/stat.h>
#include<fcntl.h>

/*
 * buffered cat, but I'm only allowed to use syscalls wrappers.
 */

#define CANT_OPEN_MSG "Cannot open file: "
#define BUFFER_SIZE 1024

static char buffer[BUFFER_SIZE] = { 0 };

void cat(int fd) {

    size_t size = 0;

    for (;;) {
        size = read(fd, buffer, BUFFER_SIZE);
        if (size == 0)
            return;
        write(1, buffer, size);
    }
}

int main(int argc, char *argv[]) {

    if (argc == 1)
        cat(0);

    for (int c = 1; c < argc; c++) {
        // this is extremelly unsafe lol but anyway...
        if ((argv[c][0] == '-') && (argv[c][1] == '\0'))
            cat(0);
        else {
            int fd = open(argv[c], O_RDONLY);
            if (fd < 0) {
                write(2, CANT_OPEN_MSG, sizeof(CANT_OPEN_MSG) - 1);
                int chr = 0;
                for (; argv[c][chr] != '\0'; chr++);
                write(2, argv[c], chr);
                write(2, "\n", 1);
            } else
                cat(fd);
        }
    }

    return 0;
}

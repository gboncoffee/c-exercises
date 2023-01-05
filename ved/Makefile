CC = clang
CFLAGS = -pedantic -Wall -Wextra -std=c11
CFILES = main.c ui.c

ved : $(CFILES)
	$(CC) $(CFLAGS) $(CFILES) -o ved

compiler_version :
	$(CC) --version

.PHONY : run test-ioctl

run : ved
	./ved

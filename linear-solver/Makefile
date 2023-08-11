CC = g++
CFLAGS = -Wall -Wextra -pedantic -std=c++11 -g
CFILES = main.cpp

main : $(CFILES)
	$(CC) $(CFLAGS) $(CFILES) -o main

.PHONY : test

test : main
	echo -e "3x3\n1 1 0\n2 1 -1\n3 -2 2\n5 6 7\n" | ./main

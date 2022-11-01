a.out : main.c
	cc main.c

.PHONY : test

test : a.out | test.txt
	cat test.txt | ./a.out
	cat test.txt

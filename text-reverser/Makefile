define NL

endef
a.out : main.c
	cc main.c

.PHONY : test

test : a.out
	./a.out "Lorem ipsum dolor sit amet"
	echo "Lorem ipsum dolor sit amet" | ./a.out

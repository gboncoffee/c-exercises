I64 a = 1;
I64 b = 2;
I64 c;
I64 it;

for (it = 10; it > 0; it--) {
	"%d\n", a;
	c = a + b;
	a = b;
	b = c;
}

"%d\n", b;

#include<stdio.h>
#include<stdlib.h>
#include<math.h>

/*
 * Reads three numbers (a, b, c) from stdin and prints the roots of the
 * quadratic equation on the form ax^2 + bx + c.
 */

double read_number_or_panic(char *msg)
{
	double n;
	printf("%s", msg);
	fflush(stdin);
	// I assume the compiler will ignore the comparison. This is more
	// expressive as I just want to parse a single value and I want to
	// compare with one and not booleaness.
	if (fscanf(stdin, "%lf", &n) == 1)
		return n;
	else {
		fprintf(stderr, "Could not convert number\n");
		exit(EXIT_FAILURE);
	}
}

int main(void)
{
	double a = read_number_or_panic("a: ");
	double b = read_number_or_panic("b: ");
	double c = read_number_or_panic("c: ");

#ifdef DEBUG
	printf("readed %lf, %lf and %lf\n", a, b, c);
#endif // DEBUG

	double delta = b * b - 4 * a * c;

#ifdef DEBUG
	printf("delta = %lf\n", delta);
#endif // DEBUG
	if (delta < 0)
		printf("No real roots.\n");
	else if (delta == 0)
		printf("%lf\n", (-b) / (2 * a));
	else {
		double delta_sqrt = sqrt(delta);
		double a2 = 2 * a;
		printf("%lf\n%lf\n", ((-b) + delta_sqrt) / a2, ((-b) - delta_sqrt) / a2);
	}

	return 0;
}

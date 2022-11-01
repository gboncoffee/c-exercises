#include<stdio.h>
#include<stdlib.h>

/*
 * author Gabriel G. de Brito gabrielgbrito@icloud.com
 * version 1.0.0
 * since Mar 08, 2022
 */

/*
 * Prints the stdin to stdout, with a linecounter
 * on the left side
 */
int main() {

    int count = 1;
    int print = 1;
    char c;

    for (;;) {
        c = getchar();

        if (c == EOF) break;

        if (print == 1) {
            printf("%i - ", count);
            print = 0;
            count++;
        }

        if (c == '\n') print = 1;
        printf("%c", c);

    }

    return(0);
}

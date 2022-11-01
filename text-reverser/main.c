#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define DEF_ALLOC 80

/*
 * author Gabriel G. de Brito gabrielgbrito@icloud.com
 * version 1.0.0
 * since Apr 19, 2022
 */

/*
 * Reverses string
 */
int reverse(char *s) {

    int dec = strlen(s) - 1;
    int inc = 0;
    char b;
    for (;;) {

        b = s[dec];
        s[dec] = s[inc];
        s[inc] = b;

        dec--;
        inc++;
        if ((dec == inc) || (dec < inc)) break;
    }

    return(0);
}

/*
 * Concatenates stdin to stdout, reversing a line at time, or, if passed with a
 * string in args, reverses it entirely.
 */
int main(int argv, char *argc[]) {

    if (argv > 1) {
        reverse(argc[1]);
        printf("%s\n", argc[1]);

    } else {

        // create buffer and vars
        int alloc_times = 1;
        char *buf = malloc((DEF_ALLOC * alloc_times + 1) * sizeof(char));
        char c;

        for (;;) {
            for (int count = 0;; count++) {

                c = getchar();

                if ((c == '\n') || (c == EOF)) {
                    buf[count] = '\0';

                    reverse(buf);
                    printf("%s\n", buf);
                    if (c == EOF) return(0);
                    break;

                }

                buf[count] = c;

                // realloc if massive line
                if ((count + 1) > (DEF_ALLOC * alloc_times)) {
                    alloc_times++;
                    buf = realloc(buf, ((DEF_ALLOC * alloc_times + 1) * sizeof(char)));

                }
            }
        }
    }

    return(0);
}

#include<stdio.h>
#include<stdlib.h>
#define BLANK 1
#define NOT_BLANK 0
#define NEWLINE 1
#define NOT_NEWLINE 0

/*
 * author Gabriel G. de Brito gabrielgbrito@icloud.com
 * version 1.0.0
 * since Apr 19, 2022
 */

/*
 * Concatenates stdin to stdout, replacing sequences of blanks with only one
 * blank and removing entire blank lines
 */
int main() {

    char c;
    unsigned short blank = NOT_BLANK;
    unsigned short newline = NEWLINE;

    for (;;) {

        c = getchar();
        if (c == EOF) break;

        if ((c == ' ') || (c == '\t')) {

            if (blank) continue;
            blank = BLANK;
            newline = NOT_NEWLINE;

        } else if (c == '\n') {

            if (newline) continue;
            newline = NEWLINE;
            blank = NOT_BLANK;

        } else {

            newline = NOT_NEWLINE;
            blank = NOT_BLANK;
        }

        printf("%c", c);
    }

    printf("\n");

    return(0);
}

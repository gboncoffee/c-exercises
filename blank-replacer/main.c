#include<stdio.h>
#include<stdlib.h>
#define BLANK 1
#define NOT_BLANK 0

/*
 * author Gabriel G. de Brito gabrielgbrito@icloud.com
 * version 1.0.0
 * since Mar 10, 2022
 */

/*
 * Concatenates stdin to stdout,
 * replacing sequences of blanks
 * with only one blank
 */
int main() {

    char c;
    int last_c = NOT_BLANK;

    for (;;) {
        c = getchar();

        if (c == EOF) break;

        if ((c == ' ') || (c == '\t')) {

            if (last_c == NOT_BLANK) {

                printf("%c", c);
                last_c = BLANK;

            } else {
                continue;

            }
        } else {
            if (last_c == BLANK) last_c = NOT_BLANK;
            printf("%c", c);

        }
    }
    
    return(0);
}

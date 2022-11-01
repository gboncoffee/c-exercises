#include<stdio.h>
#include<stdlib.h>

/*
 * author Gabriel G. de Brito gabrielgbrito@icloud.com
 * version 1.0.0
 * since Mar 11, 2022
 */

/*
 * Concatenates stdin to stdout,
 * breaking line on last blank
 * before args limit
 */

// prints num chars from *bp
int print_buf(char *bp, int num) {
    for (int count = 0; count < num; count++)
        printf("%c", bp[count]);

    return(0);
}

int main(int argv, char *argc[]) {

    char c;
    int lw;
    int length = 0;
    int wlength = 0;
    int last_blank = 0;
    char *lbuf;
    char *wbuf;
    int newline_from_before = 0;

    // get fw
    if (argv > 1) {
        lw = atoi(argc[1]);

    } else {
        fprintf(stderr, "Please specify line width.\n");
        return(1);

    }

    // alloc memory
    lbuf = malloc(lw);
    wbuf = malloc(lw);

    // main loop
    for (;;) {
        c = getchar();

        if (c == '\n' || c == EOF) {
            if (c == '\n')
                if (newline_from_before) continue;

            // prints buffer and resets vars
            print_buf(lbuf, length);
            printf("\n");
            length = 0;
            wlength = 0;
            last_blank = 0;

            if (c == EOF) break;

        } else if (c == ' ') {
            // sets last_blank and resets wlength,
            // increases length and adds new char
            last_blank = last_blank + wlength + 1;
            wlength = 0;

            lbuf[length] = c;
            length++;

        } else {
            // moves new char and increases vars
            wbuf[wlength] = c;
            wlength++;

            lbuf[length] = c;
            length++;
        }

        if ((length == lw) && (c != '\n')) {
            // if word > lw
            if (wlength == lw) {
                print_buf(lbuf, length);
                printf("\n");
                newline_from_before = 1;

                length = 0;
                wlength = 0;
                last_blank = 0;

            // prints buffer
            } else {
                print_buf(lbuf, last_blank);
                printf("\n");
                newline_from_before = 1;

                // resets vars
                length = 0;
                last_blank = 0;

                // adds word to lbuf
                for (int count = 0; count < wlength; count++) {
                    lbuf[count] = wbuf[count];
                    length++;

                }
            }

            continue;
        }

        newline_from_before = 0;
    }

    return(0);
}

#include<stdio.h>
#include<string.h>
#include<errno.h>
#define NUMBER_NBLK     0x1
#define SHOW_ENDS       0x2
#define NUMBER          0x4
#define SQUEEZE_BLANK   0x8
#define SHOW_TABS       0x10
#define SHOW_NONPRT     0x20
#define VERSION         "1.0.0"

/*
 * author Gabriel G. de Brito gabrielgbrito@icloud.com
 * version 1.0.0
 * since Apr 24, 2022
 */

/* LICENSE {{{
 * Copyright 2022 © Gabriel G. de Brito
 * 
 * Permission is hereby granted, free of charge, to any person obtaining a copy of 
 * this software and associated documentation files (the “Software”), to deal 
 * in the Software without restriction, including without limitation the rights to 
 * use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies 
 * of the Software, and to permit persons to whom the Software is furnished to do 
 * so, subject to the following conditions:
 * 
 * The above copyright notice and this permission notice shall be included in all 
 * copies or substantial portions of the Software.
 * 
 * THE SOFTWARE IS PROVIDED “AS IS”, WITHOUT WARRANTY OF ANY KIND, EXPRESS OR 
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, 
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE 
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER 
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, 
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE 
 * SOFTWARE.
 * }}}
 */

unsigned short runned_cat = 0;

int cat(FILE *in, unsigned short args) {

    if (!runned_cat) runned_cat = 1;

    char c;
    unsigned short last_newline = 1;
    unsigned short skip_char;

    for (int count = 1;;) {

        c = fgetc(in);
        if (c == EOF) break;

        skip_char = 0;

        // squeeze blank if squeeze blank
        if ((args & SQUEEZE_BLANK) && (last_newline) && (c == '\n'))
            skip_char = 1;

        // print ln if number
        if ((args & NUMBER) && (last_newline) && !skip_char) {
            printf("   %i   ", count);
            count++;

        }

        if ((args & NUMBER_NBLK) && (last_newline == 1) && (c != '\n')) {
            printf("   %i   ", count);
            count++;

        }

        if (c == '\n')
            last_newline = 1;
        else last_newline = 0;

        // print $ if show ends
        if ((args & SHOW_ENDS) && (c == '\n'))
            putchar('$');

        // show tabs if show tabs
        if ((args & SHOW_TABS) && (c == '\t')) {
            printf("^I");
            skip_char = 1;

        }

        // show nonprinting if show nonprinting
        if (args & SHOW_NONPRT) {
            if ((c <= 8) || ((c >= 11) && (c <= 31))) {
                skip_char = 1;
                printf("^%c", c + 64);

            } else if (c == 127) {
                printf("^?");
                skip_char = 1;

            }
        }

        if (!skip_char) putchar(c);

    }

    return(0);
}

int main(int argv, char *argc[]) {

    unsigned short args = 0;

    // eval args
    for (int count = 1; count < argv; count++) {

        if ((strcmp(argc[count], "-b") == 0) || (strcmp(argc[count], "--number-nonblank") == 0)) {
            args = args | NUMBER_NBLK;
            args = args & ~(NUMBER);

        } else if ((strcmp(argc[count], "-E") == 0) || (strcmp(argc[count], "--show-ends") == 0)) {
            args = args | SHOW_ENDS;

        } else if ((strcmp(argc[count], "-n") == 0) || (strcmp(argc[count], "--number") == 0)) {
            args = args | NUMBER;

        } else if ((strcmp(argc[count], "-s") == 0) || (strcmp(argc[count], "--squeeze-blank") == 0)) {
            args = args | SQUEEZE_BLANK;

        } else if ((strcmp(argc[count], "-T") == 0) || (strcmp(argc[count], "--show-tabs") == 0)) {
            args = args | SHOW_TABS;

        } else if ((strcmp(argc[count], "-v") == 0) || (strcmp(argc[count], "--show-nonprinting") == 0)) {
            args = args | SHOW_NONPRT;

        } else if (strcmp(argc[count], "--help") == 0) {
            printf("Usage is similar to GNU's version distributed with CoreUtils.\n\nAll options are the same.\n");
            runned_cat = 1; // prevent it from running with stdin
            break;

        } else if (strcmp(argc[count], "--version") == 0) {
            printf("%s\n", VERSION);
            runned_cat = 1; // prevent it from running with stdin
            break;

        } else if (strcmp(argc[count], "-u") == 0) {
            continue;

        } else if (strcmp(argc[count], "-e") == 0) {
            args = args | SHOW_NONPRT | SHOW_ENDS;

        } else if (strcmp(argc[count], "-t") == 0) {
            args = args | SHOW_NONPRT | SHOW_TABS;

        } else if ((strcmp(argc[count], "-A") == 0) || (strcmp(argc[count], "--show-all") == 0)) {
            args = args | SHOW_NONPRT | SHOW_TABS | SHOW_ENDS;

        } else if (strcmp(argc[count], "-") == 0) {
            cat(stdin, args);

        } else {
            FILE *fp = fopen(argc[count], "r");
            cat(fp, args);

        }
    }

    if (!runned_cat)
        cat(stdin, args);

    return(errno);
}

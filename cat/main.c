#include<stdio.h>
#include<stdlib.h>

/*
 * author Gabriel G. de Brito gabrielgbrito@icloud.com
 * version 1.0.1
 * since Mar 10, 2022
 */

/*
 * Nothing much to say about
 * Concatenate files to stdout, and if
 * no args, concatenates from stdin
 */
int cat(FILE *fp) {
    char c;
    for (;;) {
        c = fgetc(fp);
        if (c == EOF) break;
        printf("%c", c);

    }

    return(0);
}

int main(int argv, char *argc[]) {

    FILE *fp;
    if (argv == 1) {
        cat(stdin);

    } else {

        for (int c = 1; c < argv; c++) {
            fp = fopen(argc[c], "r");
            if (fp == NULL) {
                fprintf(stderr, "Cannot open file %s\n", argc[c]);

            } else {
                cat(fp);

            }
        }
    }

    printf("\n");
    
    return(0);
}

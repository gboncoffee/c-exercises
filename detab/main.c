#include<stdio.h>
#include<stdlib.h>

/*
 * author Gabriel G. de Brito gabrielgbrito@icloud.com
 * version 1.0.0
 * since Mar 11, 2022
 */

/*
 * Concatenates stdin to stdout,
 * replacing every tab with as much
 * as spaces as defined by args
 */
int main(int argv, char *argc[]) {

    char c;
    int spaces;

    // get spaces
    if (argv > 1) {
        spaces = atoi(argc[1]);

    } else {
        fprintf(stderr, "Please specify tab size.\n");
        return(1);

    }

    // main loop
    for (;;) {
        c = getchar();
        if (c == EOF) break;

        if (c == '\t')
            for (int count = 0; count < spaces; count++) 
                printf(" ");

        else printf("%c", c);

    }

    printf("\n");
    
    return(0);
}

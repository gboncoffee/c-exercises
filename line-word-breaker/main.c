#include<stdio.h>
#include<stdlib.h>
#define IN 1
#define OUT 0

/*
 * author Gabriel G. de Brito gabrielgbrito@icloud.com
 * version 1.0.0
 * since Mar 09, 2022
 */
int main() {

    char c;
    int state = OUT;
    for (;;) {
        c = getchar();
        if (c == EOF) {
            break;

        } else if ((c == '\t' || c == ' ' || c == '\n')) {
            if (state == IN) {     // we need to do two if because
                printf("\n");     // this way it wont print the second
                state = OUT;     // blank in a roll
            }

        } else {
            printf("%c", c);
            state = IN;

        }
    }

    printf("\n");
    
    return(0);
}

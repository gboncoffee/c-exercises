#include<stdio.h>
#include<stdlib.h>

/*
 * author Gabriel G. de Brito gabrielgbrito@icloud.com
 * version 1.0.0
 * since Mar 09, 2022
 */

/*
 * Concatenates stdin to stdout, replacing
 * each tab by \t, each backspace by \b,
 * each newline to \n and each backslash 
 * to \\.
 */
int main() {

    char c;
    for (;;) {
        c = getchar();
        if (c == EOF) break;
        else if (c == '\t') printf("\\t");
        else if (c == '\b') printf("\\b");
        else if (c == '\0') printf("\\0");
        else if (c == '\n') printf("\\n");
        else if (c == '\\') printf("\\");
        else printf("%c", c);

    }

    printf("\n");
    
    return(0);
}


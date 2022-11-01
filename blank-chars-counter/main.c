#include<stdio.h>
#include<stdlib.h>

/*
 * author Gabriel G. de Brito gabrielgbrito@icloud.com
 * version 1.0.0
 * since Mar 09, 2022
 */

/*
 * Counts blanks, tabs, spaces and newlines
 */
int main() {

    char c;
    int blanks = 0;
    int tabs = 0;
    int spaces = 0;
    int newlines = 0;

    for (;;) {
        c = getchar();
        if (c == EOF) break;
        else if (c == 255) blanks++;
        else if (c == '\t') tabs++;
        else if (c == ' ') spaces++;
        else if (c == '\n') newlines++;

        printf("%c", c);

    }

    printf("\n\n");
    printf("blanks: %i\n", blanks);
    printf("tabs: %i\n", tabs);
    printf("spaces: %i\n", spaces);
    printf("newlines: %i\n", newlines);
    printf("total: %i\n", (blanks + tabs + spaces + newlines));
    
    return(0);
}

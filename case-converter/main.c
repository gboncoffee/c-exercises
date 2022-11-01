#include<stdio.h>
#include<ctype.h>
#include<string.h>

/*
 * author Gabriel G. de Brito gabrielgbrito@icloud.com
 * version 1.0.0
 * since Mar 07, 2022
 */

/*
 * Converts lower case to upper case with -lu
 * Converts upper case to lower case with -ul
 * Reverts the case with -r
 */
int main(int argv, char *argc[]) {

    char c;

    if (argv == 1) {
        printf("Usage:\n");
        printf("-lu     to convert lower to upper\n");
        printf("-ul     to convert upper to lower\n");
        printf("-r     to revert case\n");
        return(1);
    }
    
    if (strcmp(argc[1], "-lu") == 0) {
        for (;;) {
            c = getchar();
            if (islower(c)) c = toupper(c);
            if (c == EOF) break;
            printf("%c", c);

        }

    } else if (strcmp(argc[1], "-ul") == 0) {
        for (;;) {
            c = getchar();
            if (isupper(c)) c = tolower(c);
            if (c == EOF) break;
            printf("%c", c);

        }
    
    } else if (strcmp(argc[1], "-r") == 0) {
        for (;;) {
            c = getchar();
            if (isupper(c)) c = tolower(c);
            else if (islower(c)) c = toupper(c);
            if (c == EOF) break;
            printf("%c", c);

        }
    }

    return(0);
}

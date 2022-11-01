#include<stdio.h>
#include<stdlib.h>

/*
 * author Gabriel G. de Brito gabrielgbrito@icloud.com
 * version 1.0.0
 * since Sep 19, 2022
 */

/*
 * outputs the hex bytes of the stdin, without printf()
 */
char b4tohex(unsigned short n) {

    unsigned char c;
    if (n > 0x9) { // 0b1010, 0b1011 .. 0b1111
        c = 'A';
        c += (n - 0xA);

    } else { // 0b0000, 0b0001 .. 0b1001
        c = '0';
        c += n;
    }

    return c;
}

int bytetohex(unsigned short c, char *str) {

    unsigned short l = c & 0x0F;
    unsigned short r = (c & 0xF0) >> 4;
    str[0] = b4tohex(r);
    str[1] = b4tohex(l);

    return 0;
}

int main() {

    char *str = (char*) malloc(sizeof(char) * 3);
    str[2] = '\0';
    char c;
    while ((c = getchar()) != EOF) {
        bytetohex(c, str);
        printf("%s ", str);
        if (c == '\n')
            putchar('\n');
    }

    return 0;
}

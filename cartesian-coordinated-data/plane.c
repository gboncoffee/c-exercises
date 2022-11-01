#include<stdio.h>
#include<stdlib.h>
#include<errno.h>
#include"carteplane.h"

/*
 * author Gabriel G. de Brito gabrielgbrito@icloud.com
 * version 1.0.0
 * since Aug 09, 2022
 */
Plane *new_plane(int radius) {

    Plane *plane = (Plane*) malloc(sizeof(Plane));
    plane->radius = radius;
    plane->x = malloc(sizeof(int*) * (radius * 2 + 1));

    for (int c = 0; c != radius * 2 + 1; c++)
        plane->x[c] = calloc(radius * 2 + 1, sizeof(int));

    return(plane);
}

int dump(Plane *plane) {

    for (int c = 0; c != plane->radius * 2 + 1; c++) {

        for (int inc = 0; inc != plane->radius * 2 + 1; inc++) {

            if ((plane->x)[c][inc] == 0) {
                if ((c == plane->radius) && (inc == plane->radius)) {
                    putchar('#');

                } else if (c == plane->radius) {
                    putchar('=');

                } else if (inc == plane->radius) {
                    putchar('|');

                } else {
                    putchar(' ');

                }

            } else {
                printf("%i", (plane->x)[c][inc]);
            }
        }
        putchar('\n');
    }

    return(errno);
}

int get(Plane *plane, signed int x, signed int y) {
    return((plane->x)[x + plane->radius][y + plane->radius]);
}

int set(Plane *plane, signed int x, signed int y, int value) {
    plane->x[x + plane->radius][y + plane->radius] = value;
    return(0);
}

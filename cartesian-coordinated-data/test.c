#include<stdio.h>
#include<stdlib.h>
#include<errno.h>
#include"carteplane.h"

/*
 * author Gabriel G. de Brito gabrielgbrito@icloud.com
 * version 1.0.0
 * since Aug 09, 2022
 */
int main() {

    Plane *plane = new_plane(13);
    /* set(plane,   0,   0, 1); */
    /* set(plane, -13,   0, 1); */
    /* set(plane,   0, -13, 1); */
    /* set(plane,   0,  13, 1); */
    /* set(plane,  13,   0, 1); */
    /* set(plane, -13, -13, 1); */
    /* set(plane,  13, -13, 1); */
    /* set(plane, -13,  13, 1); */
    /* set(plane,  13,  13, 1); */
    set(plane,  13,   4, 1);
    set(plane,   3,   6, 2);
    set(plane,   9,   1, 3);
    set(plane,  -9,   1, 4);
    set(plane,  -5,  -7, 5);
    set(plane, -13, -13, 6);
    set(plane,  13,  -8, 6);
    set(plane,   0,  11, 7);
    set(plane,   2,   0, 8);

    dump(plane);

    return(errno);
}

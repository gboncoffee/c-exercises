#include<stdio.h>
#include<stdlib.h>
#define DEF_ALLOC 100

/*
 * author Gabriel G. de Brito gabrielgbrito@icloud.com
 * version 1.0.0
 * since Mar 10, 2022
 */

/*
 * Reads stdin and writes a histogram
 * of the length of the words to stdout
 */
struct WordLength {
    int length;
    int occurrencies;

};

/* 
 * search if some number already occurred
 * if y, returns array position
 * if n, returns -1
 */
int search_wl_array(int length, struct WordLength *ap, int array_length) {

    for (int count = 0; count < array_length; count++)
        if (ap[count].length == length) return(count);

    return(-1);

}

// creates the histogram
int histogram(struct WordLength *ap, int array_length) {

    for (int count = 0; count < array_length; count++) {

        printf("%i - ", ap[count].length);
        for (int num = 1; num <= ap[count].occurrencies; num++)
            printf("#");

        printf(" %i\n", ap[count].occurrencies);

    }

    return(0);
}

int main() {

    char c;
    int array_length = 0;
    int wl = 0;
    int arr_pos;
    struct WordLength wlength;
    
    int cur_arr_size = DEF_ALLOC;
    struct WordLength *ap;
    ap = malloc(DEF_ALLOC * sizeof(struct WordLength));

    for (;;) {
        c = getchar();
        if ((c == '\n') || (c == '\t') || (c == ' ') || (c == EOF)) {

            if (wl != 0) {
                if ((arr_pos = search_wl_array(wl, ap, array_length)) == -1) {

                    wlength.length = wl;
                    wlength.occurrencies = 1;
                    ap[array_length] = wlength;
                    array_length++;

                    if (array_length == (cur_arr_size + DEF_ALLOC)) {
                        realloc(ap, (cur_arr_size + (sizeof(struct WordLength) * DEF_ALLOC)));
                        cur_arr_size = cur_arr_size + DEF_ALLOC;

                    }

                } else {

                    ap[arr_pos].occurrencies++;

                }

            }
            
            wl = 0;
            if (c == EOF) break;
            continue;
        }

        wl++;

    }
    
    histogram(ap, array_length);

    return(0);
}

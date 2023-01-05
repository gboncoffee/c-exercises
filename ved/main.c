#include<stdio.h>
#include<stdlib.h>
#include<errno.h>
#include<unistd.h>
#include<ctype.h>
#include<string.h>
#include"ved_ui.h"

#define WELCOME_MSG "Welcome to VED, the Visual EDitor"
#define LICENSE_MSG "VED is free and open source software licensed under the MIT License"
#define AUTHORY_MSG "Copyright (c) 2023 Gabriel G. de Brito"
#define DEVELOP_MSG "Help the development of VED: https://github.com/gboncoffee/ved"

void die(const char *s) {
    clear_scr();

    perror(s);
    exit(errno);
}

void init_editor_scr() {
    int max = max_lines();
    int col = max_cols();
    int half = max / 2;

#define DRAW_MSG(msg) \
    char *buf = (char*) malloc(sizeof(char) * ((col - sizeof(msg)) / 2));\
    unsigned long c;\
    for (c = 0; c < (col - sizeof(msg)) / 2; c++)\
        buf[c] = ' ';\
    strcpy(buf + c, msg);\
    append_str_buf(buf);\
    free(buf)

    for (int line = 1; line <= max; line++) {
        /* if (line == half - 2) { */
        /*     DRAW_MSG(WELCOME_MSG); */
        /* } else if (line == half - 1) { */
        /*     DRAW_MSG(LICENSE_MSG); */
        /* } else if (line == half) { */
        /*     DRAW_MSG(AUTHORY_MSG); */
        /* } else if (line == half + 1) { */
        /*     DRAW_MSG(DEVELOP_MSG); */
        /* } else { */
        /*     append_str_buf("~"); */
        /* } */

        append_str_buf("~");
        append_str_buf("\r\n");
    }

    redraw();
}

char get_key_or_die() {
    char c;
    if (get_key(&c))
        die("Unable to get input");
    return c;
}

void main_loop() {

    for (;;) {

        redraw();

        char c = get_key_or_die();

        switch (c) {
            case CTRL_K('q'):
                return;
                break;
        }
    }
}

int main() {

    if (init_term_control()) {
        die("Unable to get control of the terminal");
    }

    init_editor_scr();

    main_loop();

    clear_scr_reset_cur();

    return errno;
}

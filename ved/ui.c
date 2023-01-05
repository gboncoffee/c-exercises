#include<stdlib.h>
#include<stdio.h>
#include<termios.h>
#include<sys/ioctl.h>
#include<unistd.h>
#include<errno.h>
#include<string.h>
#include<assert.h>
#include"ved_ui.h"

typedef struct UIConfig {
    struct termios orig_termios;
    struct winsize winsize;
    struct Curpos curpos;
} UIConfig;

struct UIConfig ui_config; 

typedef struct Buf {
    char *buf;
    int len;
} Buf;

struct Buf buf = { NULL, 0 };

int max_lines() {
    return ui_config.winsize.ws_row;
}

int max_cols() {
    return ui_config.winsize.ws_col;
}

int append_buf(const char *text, int len) {

    char *new = realloc(buf.buf, buf.len + len);
    if (new == NULL)
        return (errno = ENOBUFS);

    memcpy(&new[buf.len], text, len);
    buf.buf = new;
    buf.len += len;

    return errno;
}

void free_buf() {
    free(buf.buf);
    buf.buf = NULL;
}

int append_str_buf(const char *s) {
    return append_buf(s, strlen(s));
}

int reload_curpos() {

    if (write(STDOUT_FILENO, "\x1b[6n", 4) != 4)
        return (errno = EIO);

    char buf[32];
    unsigned int c = 0;
    while (c < sizeof(buf) - 1) {
        if (read(STDIN_FILENO, &buf[c], 1) != 1)
            return (errno = EIO);
        if (buf[c] == 'R')
            break;
        c++;
    }
    buf[c] = '\0';

    if (buf[0] != '\x1b' || buf[1] != '[')
        return (errno = ENOTTY);
    if (sscanf(&buf[2], "%d;%d", &(ui_config.curpos.row), &(ui_config.curpos.col)) != 2)
        return (errno = ENOTTY);

    return errno;
}

void end_term_control() {

    tcsetattr(STDIN_FILENO, TCSAFLUSH, &(ui_config.orig_termios));
}

int init_term_control() {

    if (tcgetattr(STDIN_FILENO, &(ui_config.orig_termios)))
        return errno;

    atexit(end_term_control);

    struct termios raw;
    tcgetattr(STDIN_FILENO, &raw);

    raw.c_iflag &= ~(IXON | ISTRIP | BRKINT | INPCK | ICRNL);
    raw.c_lflag &= ~(ECHO | ICANON | IEXTEN | ISIG);
    raw.c_oflag &= ~(OPOST);
    raw.c_cflag |= CS8;
    raw.c_cc[VMIN]  = 0;
    raw.c_cc[VTIME] = 1;

    if (tcsetattr(STDIN_FILENO, TCSAFLUSH, &raw))
        return errno;

    if (ioctl(STDOUT_FILENO, TIOCGWINSZ, &(ui_config.winsize)) || ui_config.winsize.ws_col == 0) {
        // gambiarra
        if (write(STDOUT_FILENO, "\x1b[999C\x1b[999B", 12) != 12)
            return errno;

        reload_curpos();
        ui_config.winsize.ws_col = ui_config.curpos.col;
        ui_config.winsize.ws_row = ui_config.curpos.row;

        return errno;
    }

    return errno;
}

int get_key(char *c) {
    int nread;
    while ((nread = read(STDIN_FILENO, c, 1)) != 1) {
        if (!(nread == -1 && errno != EAGAIN))
            continue;
    }
    assert(errno == 0);
    return errno;
}

int reset_cur() {
    write(STDOUT_FILENO, "\x1b[H", 3);
    reload_curpos();
    return errno;
}

int clear_scr() {
    write(STDOUT_FILENO, "\x1b[2J", 4);
    return errno;
}

int clear_scr_reset_cur() {
    if (clear_scr())
        return errno;
    reset_cur();
    return errno;
}

int redraw() {
    if (clear_scr_reset_cur())
        return errno;

    write(STDOUT_FILENO, buf.buf, buf.len);

    free_buf();

    reset_cur();

    return errno;
}

int puts(const char *s) {
    int len = strlen(s);
    write(STDOUT_FILENO, s, len);
    reload_curpos();
    return errno;
}

int goto_next_line() {
    if (ui_config.curpos.row == ui_config.winsize.ws_row)
        return -1;
    write(STDOUT_FILENO, "\r\n", 2);
    reload_curpos();
    return errno;
}

int fill_lines(const char *s) {
    free_buf();

    int len = strlen(s);
    for (int y = 0; y < ui_config.winsize.ws_row - 1; y++) {
        if (append_buf(s, len) == ENOBUFS)
            return errno;
        if (append_buf("\r\n", 2) == ENOBUFS)
            return errno;
    }
    if (append_buf(s, len))
        return errno;

    redraw();

    return errno;
}

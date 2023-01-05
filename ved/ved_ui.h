typedef struct Curpos {
    int row;
    int col;
} Curpos;

// miscelaneous
int init_term_control();
int clear_scr();
int reset_cur();
int clear_scr_reset_cur();
int goto_next_line();
int redraw();
int max_lines();
int max_cols();

// write
int puts(const char *s);
int fill_lines(const char *s);

// buf
int append_buf(const char *s, int len);
int append_str_buf(const char *s);
void free_buf();

// input
int get_key(char *c);

#define CTRL_K(c) ((c) & 0x1f)

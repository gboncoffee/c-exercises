typedef struct Plane {
    int radius;
    int **x;
} Plane;

Plane *new_plane(int radius);
int dump(Plane *plane);
int get(Plane *plane, signed int x, signed int y);
int set(Plane *plane, signed int x, signed int y, int value);

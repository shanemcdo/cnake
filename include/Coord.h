#ifndef COORD_H
#define COORD_H

typedef struct{
    int x;
    int y;
} Coord;

Coord new_coord(int x, int y);
void print_coord(Coord coord);

#endif


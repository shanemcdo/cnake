#include<stdio.h>
#include"Coord.h"

Coord new_coord(int x, int y){
    Coord c;
    c.x = x;
    c.y = y;
    return c;
}

void print_coord(Coord coord){
    printf("Coord(x=%d, y=%d)", coord.x, coord.y);
}

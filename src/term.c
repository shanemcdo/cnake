#include<stdio.h>
#include<stdlib.h>
#include"term.h"

void move_to(int x, int y){
    printf("\033[%d;%dH", y, x);
}

void set_raw(){ // unbuffered input
    system("/bin/stty raw"); // allow unbuffered input
}

void set_cooked(){ // buffered input
    system("/bin/stty cooked"); // buffer all input
}

void clear(){ // clear the screen
    system("clear");
}

// screen coord -> game coord
//       x, y   ->  2 * x - 1, y
void put_block(Coord pos, const char* color, const char* representation){ // print a block in game coordinates
    move_to(2 * pos.x - 1, pos.y);
    printf("%s%s", color, representation);
}

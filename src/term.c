#include<stdio.h>
#include<stdlib.h>
#include"term.h"
#include"constants.h"

void move_to(int x, int y){
    printf("\033[%d;%dH", y, x);
}

void set_raw(){ // unbuffered input
    system("/bin/stty raw"); // allow unbuffered input
}

void set_cooked(){ // buffered input
    system("/bin/stty cooked"); // buffer all input
}

// screen coord -> game coord
//       x, y   ->  2 * x, y + 1
void put_block(Coord pos, const char* block){ // print a block in game coordinates
    move_to(2 * pos.x, pos.y + 2);
    printf("%s%s", block, RESET);
}

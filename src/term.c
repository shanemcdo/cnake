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

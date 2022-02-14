#include<stdio.h>
#include"term.h"

void move_to(int x, int y){
    printf("\033[%d;%dH", y, x);
}

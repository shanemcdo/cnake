#include<stdio.h>
#include"snake.h"
#include"ncurses.h"

int main(){
    initscr();
    nodelay(stdscr, TRUE);
    start();
    endwin();
    return 0;
}

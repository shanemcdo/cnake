#include<stdio.h>
#include"snake.h"
#include"ncurses.h"

int main(){
    initscr();
    nodelay(stdscr, TRUE);
    noecho();
    start();
    endwin();
    return 0;
}

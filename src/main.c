#include<stdio.h>
#include"snake.h"
#include"ncurses.h"

int main(){
    initscr(); // create window
    curs_set(0); // hide cursor
    nodelay(stdscr, TRUE); // non-blocking getch
    noecho(); // don't print to output
    start(); // play the game
    endwin(); // close window
    return 0;
}

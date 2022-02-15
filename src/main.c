#include<stdlib.h>
#include<stdio.h>
#include<time.h>
#include<ncurses.h>
#include"snake.h"
#include"constants.h"

int main(){
    srand(time(0)); // set the seed
    initscr(); // create window
    curs_set(0); // hide cursor
    nodelay(stdscr, TRUE); // non-blocking getch
    noecho(); // don't print to output
    int max_x, max_y;
    getmaxyx(stdscr, max_y, max_x);
    if(max_x < BOARD_SIZE * 2 + 1 || max_y < BOARD_SIZE + 2){
        endwin();
        printf("\033[31mERROR:\033[0m Terminal too small!\n");
        return 1;
    }
    start(); // play the game
    endwin(); // close window
    return 0;
}

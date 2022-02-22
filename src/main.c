#include<stdlib.h>
#include<stdio.h>
#include<time.h>
#include<string.h>
#include<ncurses.h>
#include"snake.h"
#include"constants.h"

int main(int argc, char** argv){
    bool loopable_walls = true;
    for(int i = 1; i < argc; i++){
        if(
            strcmp(argv[i], "-n") == 0 ||
            strcmp(argv[i], "--no-loop-walls") == 0
        ){
            loopable_walls = false;
        }
    }
    initscr(); // create window
    curs_set(0); // hide cursor
    nodelay(stdscr, TRUE); // non-blocking getch
    noecho(); // don't print to output
    int max_x, max_y;
    getmaxyx(stdscr, max_y, max_x);
    if(max_x < BOARD_SIZE_MIN * 2 + 3 || max_y < BOARD_SIZE_MIN + 3){
        endwin();
        printf("\033[31mERROR:\033[0m Terminal too small!\n");
        return 1;
    }
    srand(time(0)); // set the seed
    int score = start(loopable_walls); // play the game
    endwin(); // close window
    printf("You ate %d peices of fruit!\n", score);
    return 0;
}

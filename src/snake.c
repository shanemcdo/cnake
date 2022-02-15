#include<curses.h>
#include<unistd.h>
#include"constants.h"
#include"Deque.h"
#include"term.h"

Deque snake;
int length_to_add;
bool running;

void kbin(){
    int ch = getch();
    if(ch == EOF){ // no input
        return;
    }
    putchar(ch);
    refresh();
}

void start(){
    snake = new_deque();
    deque_push_front(&snake, new_coord(BOARD_SIZE / 2, BOARD_SIZE / 2));
    length_to_add = 3;
    running = true;
    while(running){
        kbin();
        refresh();
        usleep(50000); // wait 0.05 seconds
    }
}

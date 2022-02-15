#include"constants.h"
#include"Deque.h"
#include"ncurses.h"

Deque snake;
int length_to_add;
bool running;

void kbin(){
    putchar(getch());
}

void start(){
    snake = new_deque();
    deque_push_front(&snake, new_coord(BOARD_SIZE / 2, BOARD_SIZE / 2));
    length_to_add = 3;
    running = true;
    while(running){
        kbin();
    }
}

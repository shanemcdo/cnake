#include<curses.h>
#include<unistd.h>
#include"constants.h"
#include"Deque.h"
#include"term.h"

typedef enum{
    UP,
    DOWN,
    LEFT,
    RIGHT
} Direction;

Deque snake;
int length_to_add;
bool running;
Direction current_direction;

void kbin(){
    int ch = getch();
    switch(ch){
        case EOF: // no input
            return;
        case 'w':
            current_direction = UP;
            break;
        case 'a':
            current_direction = LEFT;
            break;
        case 's':
            current_direction = DOWN;
            break;
        case 'd':
            current_direction = RIGHT;
            break;
    }
    printf("%d", current_direction);
}

void start(){
    snake = new_deque();
    deque_push_front(&snake, new_coord(BOARD_SIZE / 2, BOARD_SIZE / 2));
    length_to_add = 3;
    running = true;
    current_direction = UP;
    while(running){
        kbin();
        refresh();
        usleep(50000); // wait 0.05 seconds
    }
}

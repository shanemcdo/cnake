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

#define DIRECTION_BUFFER_SIZE 4

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
            if(current_direction != DOWN){
                current_direction = UP;
            }
            break;
        case 'a':
            if(current_direction != RIGHT){
                current_direction = LEFT;
            }
            break;
        case 's':
            if(current_direction != UP){
                current_direction = DOWN;
            }
            break;
        case 'd':
            if(current_direction != LEFT){
                current_direction = RIGHT;
            }
            break;
    }
}

void draw(){
    put_block(snake.head->val, R_HEAD);
    if(snake.head->next != NULL){
        put_block(snake.head->next->val, R_TAIL);
    }
}

void erase_end_of_tail(){
    put_block(snake.tail->val, R_EMPTY);
}

void update(){
    Coord new_head = new_coord(snake.head->val.x, snake.head->val.y);
    switch(current_direction){
        case UP:
            new_head.y -= 1;
            break;
        case DOWN:
            new_head.y += 1;
            break;
        case LEFT:
            new_head.x -= 1;
            break;
        case RIGHT:
            new_head.x += 1;
            break;
    }
    if(
        new_head.x <= 0 ||
        new_head.y <= 0 ||
        new_head.x > BOARD_SIZE ||
        new_head.y > BOARD_SIZE
    ){
        running = false;
        return;
    }
    deque_push_front(&snake, new_head);
    if(length_to_add > 0){
        length_to_add--;
    }else{
        put_block(deque_pop_back(&snake), R_EMPTY);
    }
}

void start(){
    snake = new_deque();
    deque_push_front(&snake, new_coord(BOARD_SIZE / 2, BOARD_SIZE / 2));
    length_to_add = 3;
    running = true;
    current_direction = UP;
    while(running){
        kbin();
        update();
        draw();
        refresh();
        usleep(50000); // wait 0.05 seconds
    }
}

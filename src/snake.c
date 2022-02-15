#include<curses.h>
#include<stdlib.h>
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
Coord fruit;
int score;

void get_new_fruit(){
    const int capacity = BOARD_SIZE * BOARD_SIZE;
    Coord open_positions[BOARD_SIZE * BOARD_SIZE];
    int size = 0;
    for(int y = 1; y <= BOARD_SIZE && size < capacity; y++){
        for(int x = 1; x <= BOARD_SIZE && size < capacity; x++){
            Coord c = new_coord(x, y);
            if(!deque_contains(&snake, c)){
                open_positions[size++] = c;
            }
        }
    }
    int random_index = rand() % size;
    fruit = open_positions[random_index];
}


void draw_box(){
    addch(ACS_ULCORNER);
    for(int i = 0; i < BOARD_SIZE * 2; i++){
        addch(ACS_HLINE);
    }
    addch(ACS_URCORNER);
    addch('\n');
    for(int y = 0; y < BOARD_SIZE; y++){
        addch(ACS_VLINE);
        for(int x = 0; x < BOARD_SIZE; x++){
            printw(R_EMPTY);
        }
        addch(ACS_VLINE);
        addch('\n');
    }
    addch(ACS_LLCORNER);
    for(int i = 0; i < BOARD_SIZE * 2; i++){
        addch(ACS_HLINE);
    }
    addch(ACS_LRCORNER);
}

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
    // fruit
    put_block(fruit, R_FRUIT);
    // snake
    put_block(snake.head->val, R_HEAD);
    if(snake.head->next != NULL){
        put_block(snake.head->next->val, R_TAIL);
    }
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
        new_head.y > BOARD_SIZE ||
        deque_contains(&snake, new_head)
    ){
        running = false;
        return;
    }
    if(coord_equals(snake.head->val, fruit)){
        length_to_add += TAIL_INC;
        score++;
        get_new_fruit();
    }
    deque_push_front(&snake, new_head);
    if(length_to_add > 0){
        length_to_add--;
    }else{
        put_block(deque_pop_back(&snake), R_EMPTY);
    }
}

int start(){
    draw_box();
    snake = new_deque();
    deque_push_front(&snake, new_coord(BOARD_SIZE / 2, BOARD_SIZE / 2));
    length_to_add = 3;
    running = true;
    current_direction = UP;
    get_new_fruit();
    score = 0;
    while(running){
        kbin();
        update();
        draw();
        refresh();
        usleep(SLEEP_INTERVAL);
    }
    return score;
}

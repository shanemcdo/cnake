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

static Deque snake;
static int length_to_add;
static bool running;
static Direction current_direction;
static Coord fruit;
static int score;
static bool paused;

static void get_new_fruit(){
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

static void update_score(){
    move(0, 0);
    printw("Score: %d\n", score);
}

static void draw_box(){
    update_score();
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

static void kbin(){
    int ch = getch();
    if(ch == 'p'){
        paused = !paused;
    }
    if(ch == EOF){
        return;
    }
    if(paused){
        switch(ch){
            case 'q':
                running = false;
                break;
            case 'p':
                put_block(PAUSE_MENU_POS, PAUSE_MENU_TEXT);
                refresh();
                break;
        }
    }else{
        switch(ch){
            case 'p':
                put_block(PAUSE_MENU_POS, PAUSE_MENU_EMPTY);
                refresh();
                break;
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
}

static void draw(){
    // fruit
    put_block(fruit, R_FRUIT);
    // snake
    put_block(snake.head->val, R_HEAD);
    if(snake.head->next != NULL){
        put_block(snake.head->next->val, R_TAIL);
    }
}

static void update(){
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
        update_score();
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
    paused = false;
    while(running){
        kbin();
        if(!paused){
            update();
            draw();
            refresh();
        }
        usleep(SLEEP_INTERVAL);
    }
    return score;
}

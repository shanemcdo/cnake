#include<stdio.h>
#include<stdlib.h>
#include"Deque.h"
#include"term.h"

int main(){
    Deque d = new_deque();
    deque_push_back(&d, new_coord(1, 2));
    deque_push_back(&d, new_coord(3, 4));
    deque_push_back(&d, new_coord(5, 6));
    deque_push_front(&d, new_coord(-1, 0));
    deque_print(&d);
    print_coord(deque_pop_front(&d));
    printf("\n");
    print_coord(deque_pop_back(&d));
    printf("\n");
    deque_print(&d);
    deque_print(&d);
    system("/bin/stty raw"); // allow unbuffered input
    getchar();
    system("/bin/stty cooked"); // buffer all input
    return 0;
}

#include<stdio.h>
#include"Deque.h"
#include"constants.h"
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
    printf("%s%s%s%s",
        R_FRUIT,
        R_HEAD,
        R_TAIL,
        RESET
    );
    return 0;
}

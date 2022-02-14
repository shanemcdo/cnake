#ifndef DEQUE_H
#define DEQUE_H

#include<stdbool.h>
#include"Node.h"

typedef struct{
    Node* head;
    Node* tail;
} Deque;

Deque new_deque();
void deque_push_front(Deque* deque, Coord val);
void deque_push_back(Deque* deque, Coord val);
Coord deque_pop_front(Deque* deque);
Coord deque_pop_back(Deque* deque);
bool deque_is_empty(Deque* deque);
unsigned deque_length(Deque* deque);
void deque_print(Deque* deque);

#endif // DEQUE_H

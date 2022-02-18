#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include"Deque.h"

Deque new_deque(){
    Deque d;
    d.head = NULL;
    d.tail = NULL;
    return d;
}

void deque_push_front(Deque* deque, Coord val){
    Node* new = new_node_ptr(val, deque->head, NULL);
    if(deque_is_empty(deque)){
        deque->head = new;
        deque->tail = new;
    }else{
        deque->head->prev = new;
        deque->head = deque->head->prev;
    }
}

void deque_push_back(Deque* deque, Coord val){
    Node* new = new_node_ptr(val, NULL, deque->tail);
    if(deque_is_empty(deque)){
        deque->head = new;
        deque->tail = new;
    }else{
        deque->tail->next = new;
        deque->tail = deque->tail->next;
    }
}

Coord deque_pop_front(Deque* deque){
    assert(!deque_is_empty(deque)); // it is not allowed to be empty
    Node* to_remove = deque->head;
    deque->head = deque->head->next;
    if(deque->head == NULL){
        deque->tail = NULL;
    } else {
        deque->head->prev = NULL;
    }
    Coord result = to_remove->val;
    free(to_remove);
    return result;
}

Coord deque_pop_back(Deque* deque){
    assert(!deque_is_empty(deque)); // it is not allowed to be empty
    Node* to_remove = deque->tail;
    deque->tail = deque->tail->prev;
    if(deque->tail == NULL){
        deque->head = NULL;
    }else{
        deque->tail->next = NULL;
    }
    Coord result = to_remove->val;
    free(to_remove);
    return result;
}

bool deque_is_empty(Deque* deque){
    return deque->head == NULL;
}

unsigned deque_length(Deque* deque){
    unsigned result = 0;
    Node* current = deque->head;
    while(current != NULL){
        current = current->next;
        result++;
    }
    return result;
}

void deque_print(Deque* deque){
    Node* current = deque-> head;
    while(current != NULL){
        print_coord(current->val);
        if(current->next != NULL){
            printf(" -> ");
        }
        current = current-> next;
    }
    printf("\n");
}

bool deque_contains(Deque* deque, Coord coord){
    Node* current = deque-> head;
    while(current != NULL){
        if(coord_equals(current->val, coord)){
            return true;
        }
        current = current-> next;
    }
    return false;
}

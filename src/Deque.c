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
    Node* new = new_node_ptr(val, deque->head, NULL); // create new node before head
    if(deque_is_empty(deque)){ // if no items are in the deque
        deque->head = new; // set head
        deque->tail = new; // set tail
    }else{
        deque->head->prev = new; // put before head
        deque->head = deque->head->prev; // point to new head
    }
}

void deque_push_back(Deque* deque, Coord val){
    Node* new = new_node_ptr(val, NULL, deque->tail);
    if(deque_is_empty(deque)){ // if no items are in the deuqe
        deque->head = new; // set head
        deque->tail = new; // set tail
    }else{
        deque->tail->next = new; // put after tail
        deque->tail = deque->tail->next; // point to new tail
    }
}

Coord deque_pop_front(Deque* deque){
    assert(!deque_is_empty(deque)); // it is not allowed to be empty
    Node* to_remove = deque->head; // save head to remove
    deque->head = deque->head->next; // move head one to the right
    if(deque->head == NULL){ // if the list is empty
        deque->tail = NULL; // the tail shouldn't point to anything
    } else { // list not empty
        deque->head->prev = NULL; // there shouldn't be anything before head
    }
    Coord result = to_remove->val; // get value to return
    free(to_remove); // delete old head
    return result;
}

Coord deque_pop_back(Deque* deque){
    assert(!deque_is_empty(deque)); // it is not allowed to be empty
    Node* to_remove = deque->tail; // save tail to remove
    deque->tail = deque->tail->prev; // move tail one back
    if(deque->tail == NULL){ // if the tail moved back to nothing
        // list is empty
        deque->head = NULL; // head shouldn't point to anything
    }else{ // list isn't empty
        deque->tail->next = NULL; // nothing should be after tail
    }
    Coord result = to_remove->val; // get value to return
    free(to_remove); // delete old tail
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
    Node* current = deque->head; // start at head
    while(current != NULL){ // while current exists
        if(coord_equals(current->val, coord)){ // if the values are equal
            return true; // exit with true
        }
        current = current-> next; // increment through list
    }
    return false;
}

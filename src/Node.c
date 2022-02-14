#include<stdlib.h>
#include"Node.h"

Node new_node(Coord val, Node* next, Node* prev){
    Node n;
    n.val = val;
    n.next = next;
    n.prev = prev;
    return n;
}

Node* new_node_ptr(Coord val, Node* next, Node* prev){
    Node* n = malloc(sizeof(Node));
    if(n != NULL){
        n->val = val;
        n->next = next;
        n->prev = prev;
    }
    return n;
}

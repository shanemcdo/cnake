#ifndef NODE_H
#define NODE_H

#include"Coord.h"

typedef struct _Node{
    Coord val;
    struct _Node* next;
    struct _Node* prev;

} Node;

Node new_node(Coord val, Node* next,  Node* prev);
Node* new_node_ptr(Coord val, Node* next,  Node* prev);

#endif // NODE_H

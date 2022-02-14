#include<Node.h>


Node new_node(Coord val, Node* next, Node* prev){
    Node n;
    n.val = val;
    n.next = next;
    n.prev = prev;
    return n;
}

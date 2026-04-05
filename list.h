#ifndef LIST_H
#define LIST_H

typedef struct Node {
    double price;
    struct Node* next;
}Node;

typedef struct Node Node;
void addAtBeginning (Node **head, double price);
void addAtEnd (Node **head, double price);
void print(Node* head);

#endif

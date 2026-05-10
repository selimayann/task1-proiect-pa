#ifndef STOCK_LIST_H
#define STOCK_LIST_H

typedef char Data[100];

struct Elem {
    Data val;
    struct Elem* next;
};
typedef struct Elem Node;

void addAtBeginning (Node **head, const char *v);
void addAtEnd (Node **head, const char *v);
void deleteList (Node **head);

#endif
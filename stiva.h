#ifndef STIVA_H
#define STIVA_H

typedef double DataStiva;

struct ElemStiva {
    DataStiva val;
    struct ElemStiva *next;
};
typedef struct ElemStiva Node;

void push(Node **top, DataStiva v);

DataStiva pop(Node **top);


int isEmptyStiva(const Node *top);

void deleteStiva(Node **top);

#endif
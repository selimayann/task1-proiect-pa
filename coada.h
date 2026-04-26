#ifndef COADA_H
#define COADA_H

typedef struct {
    int ziua;
    double diferenta;
    char piata[50];
} DataCoada;


struct ElemCoada {
    DataCoada val;
    struct ElemCoada *next;
};
typedef struct ElemCoada NodeCoada;


struct Q {
    NodeCoada *front, *rear;
};
typedef struct Q Queue;


Queue* createQueue();

void enQueue(Queue *q, DataCoada v);

DataCoada deQueue(Queue *q);

int isEmptyCoada(const Queue *q);

void deleteQueue(Queue *q);

#endif
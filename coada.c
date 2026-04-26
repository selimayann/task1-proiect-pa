#include <stdio.h>
#include <stdlib.h>
#include "coada.h"

Queue* createQueue() {
    Queue *q = (Queue*)malloc(sizeof(Queue));

    if (q == NULL) return NULL;

    q->front = q->rear = NULL;

    return q;
}

void enQueue(Queue *q, DataCoada v) {

    NodeCoada *newNode = (NodeCoada*)malloc(sizeof(NodeCoada));

    newNode->val = v;
    newNode->next = NULL;

    if (q->rear == NULL) q->rear = newNode;
    else {
        (q->rear)->next = newNode;
        (q->rear) = newNode;
    }

    if (q->front == NULL) 
    q->front = q->rear;
}

DataCoada deQueue(Queue *q) {
    NodeCoada *aux;
    DataCoada d;

    aux = q->front;
    d = aux->val;
    q->front = (q->front)->next;

    if (q->front == NULL)
        q->rear = NULL;

    free(aux);
    return d;
}

int isEmptyCoada(const Queue *q) {
    return (q->front == NULL);
}

void deleteQueue(Queue *q) {

    while (!isEmptyCoada(q)) {
        NodeCoada *aux = q->front;
        q->front = q->front->next;
        free(aux);
    }

    free(q);
}
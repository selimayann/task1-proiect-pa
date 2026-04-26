#include <stdio.h>
#include <stdlib.h>
#include "stiva.h"

void push(Node **top, DataStiva v) {

    Node *newNode = (Node*)malloc(sizeof(Node));

    newNode->val = v;
    newNode->next = *top;
    *top = newNode;
}

DataStiva pop(Node **top) {
    if (isEmptyStiva(*top)) return -1;
    Node *temp = (*top);

    DataStiva aux = temp->val;
    *top = (*top)->next;

    free(temp);
    return aux;
}


int isEmptyStiva(const Node *top) {
    return top == NULL;
}

void deleteStiva(Node **top) {

    while ((*top) != NULL) {
    Node *temp = *top;
        *top = (*top)->next;
        free(temp);
    }
}
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "stock_list.h"

void addAtBeginning (Node **head, const char *v) {
    Node *newNode = (Node*) malloc(sizeof(Node));

    if(newNode == NULL) return;

    strcpy(newNode->val, v);
    newNode->next = *head;
    *head = newNode;
}

void addAtEnd (Node **head, const char *v) {
    Node *aux = *head;
    if(*head == NULL){
        addAtBeginning(head, v);
        return;
    }

    Node *newNode = (Node*) malloc(sizeof(Node));
    if (newNode == NULL) return;

    strcpy(newNode -> val, v);
    newNode->next = NULL;

    while (aux->next != NULL)
    aux = aux->next;

aux->next=newNode;
}


void deleteList(Node **head) {
    Node* headcopy;

    while(*head !=NULL){
        headcopy = (*head) -> next;
        free(*head);
        *head = headcopy;
    }
    *head = NULL;
}
#include <stdio.h>
#include <stdlib.h>
#include "list.h"

void addAtBeginning (Node **head, double price) {
    Node* new = malloc(sizeof(Node));
    new->price = price;
    new->next = *head;
    *head = new;
}

void addAtEnd (Node **head, double price) {
    Node* aux = *head;
    Node* new = (Node*)malloc(sizeof(Node));
    new->price = price;
    new->next = NULL;
    if (*head == NULL) addAtBeginning(head, price);
    else { while (aux -> next != NULL) aux = aux->next;
        aux->next = new;
        new->next = NULL; }
}

void print(Node* head) {
    while (head != NULL) {
        printf("%lf \n ", head->price);
        head = head->next;
    }
}

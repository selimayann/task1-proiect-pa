#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "coada.h"
#include "stiva.h"

int main() {
    FILE *in = fopen("in2.txt", "r");
    FILE *out = fopen("out2.txt", "w");

    Node *stiva1 = NULL;
    Node *stiva2 = NULL;
    Node *stiva3 = NULL;

    char name1[100], name2[100], name3[100];


    double price;

    fgets(name1, 50, in);
    
    if (name1[strlen(name1) - 1] == '\n')
        name1[strlen(name1) - 1] = '\0';
    
    while (fscanf(in, "%lf", &price) == 1) {
        push(&stiva1, price);
    }


    fgets(name2, 50, in);
    if (name2[strlen(name2) - 1] == '\n')
        name2[strlen(name2) - 1] = '\0';

    while (fscanf(in, "%lf", &price) == 1) {
        push(&stiva2, price);
    }

    fgets(name3, 50, in);
    if (name3[strlen(name3) - 1] == '\n')
        name3[strlen(name3) - 1] = '\0';
    while (fscanf(in, "%lf", &price) == 1) {
        push(&stiva3, price);
    }

    Queue *q = createQueue();
    int ziua = 1;
    double dif;

    while (stiva1 != NULL && stiva2 != NULL && stiva3!= NULL){
        double p1 = pop(&stiva1);
        double p2 = pop(&stiva2);
        double p3 = pop(&stiva3);

        DataCoada arb;
        arb.ziua = ziua;

        if (p1 == p2 && p2 !=p3){
            dif = p3-p1;
            if (dif < 0) dif = -dif;
            arb.diferenta = dif;
            strcpy(arb.piata, name3);
            enQueue(q, arb);
        } else if (p1 == p3 && p3 != p2){
            dif = p2-p1;
            if (dif < 0) dif = -dif;
            arb.diferenta = dif;
            strcpy(arb.piata, name2);
            enQueue(q, arb);
        } else if (p2 == p3 && p3 != p1){
            dif = p1-p2;
            if (dif < 0) dif = -dif;
            arb.diferenta = dif;
            strcpy(arb.piata, name1);
            enQueue(q, arb);
        }

        ziua ++;

        }

        while (q->front != NULL) {
            DataCoada arb = deQueue(q);
            fprintf(out, "ziua %d - %lf - %s\n", arb.ziua, arb.diferenta, arb.piata);

    }
    deleteStiva(&stiva1);

    deleteStiva(&stiva2);

    deleteStiva(&stiva3);

    deleteQueue(q);

    fclose(in);
    fclose(out);
    return 0;

}

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "list.h"

int main(int argc, const char *argv[]) {
    FILE *in = fopen(argv[1], "r");
    FILE *out = fopen(argv[2], "w");
    int n;
    double p;

    fscanf(in, "%d", &n);

    Node* head = NULL;

    for (int i = 0; i < n ; i++) {
        fscanf (in, "%lf", &p);
        addAtEnd(&head, p);
    }

    if (head !=NULL) print(head);

    if (head == NULL || head -> next ==NULL) {
        fprintf(out, "nu se poate calcula");
        fclose(out);
        fclose(in);
        return 0;
    }

    double suma1 = 0, suma2 = 0, mediaR, sigma, sRatio;

    const Node* np = head;
    const Node* nc = head -> next;

    while  (nc != NULL) {
    double Rt = (nc -> price - np -> price) / np -> price;
    suma1 = suma1 + Rt;
    suma2 = suma2 + (Rt * Rt);

    np = nc;
    nc = nc -> next;
    }
    mediaR = suma1 / (n-1);
    sigma = sqrt(suma2 / (n-1) - (mediaR * mediaR));
    sRatio = mediaR / sigma;

    fprintf(out, "randamentul mediu = %lf \n", mediaR);
    fprintf(out, "volatilitatea = %lf \n", sigma);
    fprintf(out, "sharpe ratio = %lf \n", sRatio);
    
    fclose(out);
    fclose(in);
}
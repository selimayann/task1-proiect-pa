#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "tree.h"

int main(int argc, const char *argv[]) {
    FILE *in = fopen(argv[1], "r");
    FILE *out = fopen(argv[2], "w");

    char l[500], sym[50][100]; const char *y;
    double price[1000][50], p[1000];
    int n = 0, days = 0;
    TreeNode* root = NULL;


    //citesc numele actiunilor de pe prima linie
    fgets(l, 500, in);\
    y = strtok(l, ",\n");
    while(y != NULL) {
        strcpy(sym[n], y);
        n++;
        y=strtok(NULL, ",\n");
    }


    //citesc preturile zilnice
    while(fgets(l, 500, in) != NULL){
        y = strtok(l, ",\n");
        int j = 0;
        while(y != NULL){
            sscanf(y, "%lf", &price[days][j]);
            y = strtok(NULL, ",\n");
            j++;
        }
        days++;
    }


    //construiesc arborele
    root = newNode(1);
    for(int i = 0; i < n; i++){
        for(int j = 0; j < days; j++)
            p[j] = price[j][i];
        addStock(root, sym[i], p, 1, days);
    }

    //pt fiecare actiune i, coboram pe drumul opus in arbore si vedem ce actiuni j>i sunt in frunza oglindita
    char pairs[100][50];
    int cnt = 0;

    for(int i = 0; i < n; i++){
        TreeNode* newNoden = root;
        int d = 1;

        while(d < days && newNoden != NULL){
            if(price[d][i] < price[d-1][i]){
                newNoden = newNoden->right; // a scazut, ogl creste, in dreapta
            } else{
                newNoden = newNoden->left;// a crescut/egal, ogl scade, in stanga
            }
            d++;
        }

        if(newNoden != NULL){
            for(int j = i + 1; j < n; j++){
            if(List(newNoden->stock, sym[j])){
                sprintf(pairs[cnt], "%s-%s", sym[i], sym[j]);
                cnt++;
            }
            }
        }
    }
//printez fara enter la final pt ca nu mergeau refs-urile
    for(int k = 0; k <cnt; k++){
        if(k < cnt- 1)
            fprintf(out, "%s\n", pairs[k]);
        else
            fprintf(out, "%s", pairs[k]);
    }



    deleteTree(root);
    fclose(in);
    fclose(out);

    return 0;
    }
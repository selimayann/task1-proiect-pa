#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "tree.h"

TreeNode* newNode(int d){
    TreeNode* Noden = (TreeNode*) malloc(sizeof(TreeNode));

    if(Noden == NULL) return NULL;

    Noden->stock = NULL;
    Noden->left = NULL;
    Noden->right = NULL;
    Noden->d = d;

    return Noden;
}


//adaug acctiunea doar in frunza
void addStock(TreeNode* root, char *v, double *p, int day, int n){
Node *head;

if (day>= n){
    //verif sa nu fie adaugata de 2 ori
    int ok = 0;
    head = root -> stock;

    while (head !=NULL){
        if(strcmp(head->val, v) == 0) ok = 1;
        head = head -> next;
    }
    if (ok == 0) addAtEnd(&(root->stock), v);
    return;
}

if(p[day] < p[day - 1]){
    //daca pretul a scazut, merge in stanga
    if(root -> left == NULL) root -> left = newNode(day + 1);
    addStock(root->left, v, p, day + 1, n);
}else {
    //daca pretul a crescut sau e egal, merge in dreapta
    if(root->right == NULL) root->right = newNode(day + 1);
    addStock(root->right, v, p, day + 1, n);
}
}

//cauta un simbol intr-o lista
int List (Node* head, const char *v){
    while (head != NULL){
        if (strcmp(head -> val, v) == 0) return 1;
    head = head->next;
    }
    return 0;
}

void deleteTree(TreeNode* root){
    if(root == NULL) return;

    deleteTree(root -> left);
    deleteTree(root -> right);
    deleteList(&(root -> stock));
    free(root);
}
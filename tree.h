#ifndef TREE_H
#define TREE_H

#include "stock_list.h"

struct TreeNode {
    Node* stock;
    struct TreeNode* left;
    struct TreeNode* right;
    int d;
};
typedef struct TreeNode TreeNode;

TreeNode* newNode(int d);
void addStock(TreeNode* root, char *v, double *p, int day, int n);
void deleteTree(TreeNode* root);
int List (Node* head, const char *v);

#endif
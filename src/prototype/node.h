#ifndef AVL_TEST_H
#define AVL_TEST_H

#include "element.h"

typedef struct Node {
    Element key;
    struct Node* left;
    struct Node* right;
    int height;
} Node;

Node* create_node(Element key);
void update_height(Node* node);
void node_print(Node* node);
void update_all_heights(Node* root);

#endif
#include "rotations.h"

#include <stddef.h>

Node* rotate_right(Node* node) {
    if (node == NULL || node->left == NULL)
        return node;

    Node* new_root = node->left;
    node->left = new_root->right;
    new_root->right = node;

    update_height(node);
    update_height(new_root);

    return new_root;
}

Node* rotate_left(Node* node) {
    if (node == NULL || node->right == NULL)
        return node;

    Node* new_root = node->right;
    node->right = new_root->left;
    new_root->left = node;

    update_height(node);
    update_height(new_root);

    return new_root;
}
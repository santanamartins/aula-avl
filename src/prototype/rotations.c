#include "rotations.h"

Node* rotate_right(Node* node) {
    Node* pivot = node->left;

    node->left = pivot->right;
    pivot->right = node;

    update_height(node);
    update_height(pivot);

    return pivot;
}

Node* rotate_left(Node* node) {
    Node* pivot = node->right;

    node->right = pivot->left;
    pivot->left = node;

    update_height(node);
    update_height(pivot);

    return pivot;
}

Node* rotate_left_right(Node* node) {
    node->left = rotate_left(node->left);
    return rotate_right(node);
}

Node* rotate_right_left(Node* node) {
    node->right = rotate_right(node->right);
    return rotate_left(node);
}
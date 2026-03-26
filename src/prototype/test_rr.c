#include "node.h"
#include "rotations.h"

#include <stdio.h>

Node* make_sample_tree() {
    Node* root = create_node(10);

    root->left = create_node(5);
    root->right = create_node(20);
    root->right->left = create_node(15);
    root->right->right = create_node(25);
    root->right->right->right = create_node(30);

    update_all_heights(root);

    return root;
}



int main() {
    Node* root = make_sample_tree();

    printf("Before rotation:\n");
    node_print(root);
    printf("\n");
    printf("After rotation:\n");
    root = rotate_left(root);
    node_print(root);

    return 0;
}
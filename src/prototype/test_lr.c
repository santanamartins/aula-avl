#include "node.h"
#include "rotations.h"

#include <stdio.h>

// TODO: change the tree
Node* make_sample_tree() {
    Node* root = create_node(15);

    root->left = create_node(10);
    root->left->left = create_node(5);
    root->left->right = create_node(13);
    root->left->right->left = create_node(12);
    root->right = create_node(20);

    update_all_heights(root);

    return root;
}

int main() {
    Node* root = make_sample_tree();

    printf("Before rotation:\n");
    node_print(root);
    printf("\n");
    printf("After rotation:\n");
    root = rotate_left_right(root);
    node_print(root);
    return 0;
}
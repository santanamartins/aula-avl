/**
 * Binary Search Tree implementation with AVL balancing.
*/

#include "avl.h"

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "node.h"
#include "rotations.h"

struct AVL {
    Node* root;
};

AVL* avl_create() {
    AVL* bst = malloc(sizeof(AVL));

    bst->root = NULL;

    return bst;
}

void destroy_recur(Node* node) {
    if (node == NULL) {
        return;
    }
    destroy_recur(node->left);
    destroy_recur(node->right);
    free(node);
}

void avl_destroy(AVL* bst) {
    destroy_recur(bst->root);
    free(bst);
}

bool search_recur(Node* node, Element key) {
    if (node == NULL) {
        return false;
    }
    if (node->key == key) {
        return true;
    }
    if (key < node->key) {
        return search_recur(node->left, key);
    } 
    
    return search_recur(node->right, key);
}

bool avl_search(AVL* bst, Element key) {
    return search_recur(bst->root, key);
}


Node* rebalance(Node* node) {
    if (node != NULL) {
        update_height(node);

        int bf_root = balance_factor(node);
        int bf_left = balance_factor(node->left);
        int bf_right = balance_factor(node->right);

        if (bf_root < -1 && bf_right <= 0) { // RR -> L
            return rotate_left(node);
        }
        if (bf_root < -1 && bf_right > 0) { // RL -> RL
            return rotate_right_left(node);
        }
        if (bf_root > 1 && bf_left >= 0) { // LL -> R 
            return rotate_right(node);
        }
        if (bf_root > 1 && bf_left < 0) { // LR -> LR
            return rotate_left_right(node);
        }
    }

    return node;
}

Node* insert_recur(Node* node, Element key) {
    if (node == NULL) {
        return create_node(key);
    }
    if (key < node->key) {
        node->left = insert_recur(node->left, key);
    } else if (key > node->key) {
        node->right = insert_recur(node->right, key);
    }

    return rebalance(node);
}

void avl_insert(AVL* bst, Element key) {
    bst->root = insert_recur(bst->root, key);
}

Node* successor(Node* node) {
    if (node == NULL) {
        return NULL;
    }

    Node* cur = node->right;

    while (cur->left != NULL) {
        cur = cur->left;
    }

    return cur;
}

Node* remove_recur(Node* node, Element key) {
    if (node == NULL) {
        return node;
    }
    if (key < node->key) {
        node->left = remove_recur(node->left, key);
    } else if (key > node->key) {
        node->right = remove_recur(node->right, key);
    } else {
        if (node->left == NULL) {
            Node* trash = node;

            node = node->right;
            free(trash);
        } else if (node->right == NULL) {
            Node* trash = node;

            node = node->left;
            free(trash);
        } else {
            Node* temp = successor(node);

            node->key = temp->key;
            node->right = remove_recur(node->right, temp->key);
        }
    }

    return rebalance(node);
}

void avl_remove(AVL* bst, Element key) {
    bst->root = remove_recur(bst->root, key);
}

void avl_print(AVL* bst) {
  print_diagram(bst->root, 0);
}
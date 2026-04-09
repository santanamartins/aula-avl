/**
 * Binary Search Tree implementation with AVL balancing.
*/

#include "avl.h"

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "node.h"

// TODO: include rotation logicc
// TODO: remove manual height updates 

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


Node* insert_recur(Node* node, Element key) {
    if (node == NULL) {
        return create_node(key);
    }
    if (key < node->key) {
        node->left = insert_recur(node->left, key);
    } else if (key > node->key) {
        node->right = insert_recur(node->right, key);
    }

    return node;
}

void avl_insert(AVL* bst, Element key) {
    bst->root = insert_recur(bst->root, key);
    update_all_heights(bst->root);
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

    return node;
}

void avl_remove(AVL* bst, Element key) {
    bst->root = remove_recur(bst->root, key);  
    update_all_heights(bst->root);
}

void avl_print(AVL* bst) {
  print_diagram(bst->root, 0);
}
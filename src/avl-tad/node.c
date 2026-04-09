#include "node.h"

#include <stdlib.h>
#include <stdio.h>

Node* create_node(Element key) {
    Node* node = malloc(sizeof(Node));
    node->key = key;
    node->left = NULL;
    node->right = NULL;
    node->height = 1;

    return node;
}

void fill_spaces(int size) {
    for (int i = 0; i < size; i++) {
        printf(" ");
    }
}

int maximum(int a, int b) {
    return (a > b) ? a : b;
}

int height(Node* node) {
    if (node == NULL) {
        return 0;
    }

    return node->height;
}

void update_height(Node* node) {
    if (node != NULL) {
        node->height = 1 + maximum(height(node->left), height(node->right));
    }
}

int balance_factor(Node* node) {
    if (node == NULL) {
        return 0;
    }

    return height(node->left) - height(node->right);
}

void print_diagram(Node* node, int level) {
  if (node == NULL) {
      return;
  }
  for (int i = 0; i < level; i++) {
    printf("  ");
  }
  element_print(node->key);
  printf(" %d %d ", height(node), balance_factor(node));
  printf("\n");
  print_diagram(node->left, level + 1);  
  print_diagram(node->right, level + 1);
}

void node_print(Node* node) {
  print_diagram(node, 0);
}

void update_all_heights(Node* root) {
    if (root != NULL) {
        update_all_heights(root->left);
        update_all_heights(root->right);
        update_height(root);
    }
}


Node* destroy_tree(Node* node) {
    if (node == NULL) {
        return NULL;
    }
    destroy_tree(node->left);
    destroy_tree(node->right);
    free(node);

    return NULL;
}
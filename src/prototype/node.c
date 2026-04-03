#include "node.h"

#include <stdlib.h>
#include <stdio.h>

Node* create_node(Element key) {
    Node* node = (Node*)malloc(sizeof(Node));
    if (node == NULL)
        return NULL;
    node->key = key;
    node->left = NULL;
    node->right = NULL;
    node->height = 1;
    return node;
}

static int height(Node* node) {
    return node == NULL ? 0 : node->height;
}

static int maximum(int a, int b) {
    return a > b ? a : b;
}

static int balance_factor(Node* node) {
    return node == NULL ? 0 : height(node->left) - height(node->right);
}

void update_height(Node* node) {
    if (node == NULL)
        return;
    node->height = 1 + maximum(height(node->left), height(node->right));
}

void fill_spaces(int size) {
    for (int i = 0; i < size; i++) {
        printf(" ");
    }
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
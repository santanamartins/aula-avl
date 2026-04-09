#include "avl.h"

#include <stdio.h>

void test_insertion() {
    AVL* tree = avl_create();

    for (int i = 0; i < 7; i++) {
        avl_insert(tree, i + 1);
    }

    printf("=== Insertion test (1..7) ===\n");
    avl_print(tree);
    printf("\n");

    avl_destroy(tree);
}

void run_removal_case(const char* name, const int* keys, int size, int remove_key) {
    AVL* tree = avl_create();

    for (int i = 0; i < size; i++) {
        avl_insert(tree, keys[i]);
    }

    printf("=== %s ===\n", name);
    printf("Before remove(%d):\n", remove_key);
    avl_print(tree);

    avl_remove(tree, remove_key);

    printf("After remove(%d):\n", remove_key);
    avl_print(tree);
    printf("\n");

    avl_destroy(tree);
}

void test_removal_rotations() {
    int ll_case[] = {30, 20, 40, 10, 25, 50, 5};
    int lr_case[] = {30, 20, 40, 10, 25, 50, 27};
    int rr_case[] = {30, 20, 40, 10, 35, 50, 60};
    int rl_case[] = {30, 20, 40, 10, 35, 50, 33};

    run_removal_case("LL on removal (single right rotation)", ll_case, 7, 50);
    run_removal_case("LR on removal (left-right double rotation)", lr_case, 7, 50);
    run_removal_case("RR on removal (single left rotation)", rr_case, 7, 10);
    run_removal_case("RL on removal (right-left double rotation)", rl_case, 7, 10);
}


int main(int argc, char const *argv[]) {
    

    test_insertion();
    test_removal_rotations();
    
    return 0;
}
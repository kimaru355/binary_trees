#include <stdlib.h>
#include <stdio.h>
#include "binary_trees.h"

/**
 * basic_tree - Build a basic binary tree
 *
 * Return: A pointer to the created tree
 */
binary_tree_t *basic_tree(void)
{
    binary_tree_t *the_root;

    the_root = binary_tree_node(NULL, 98);
    the_root->left = binary_tree_node(the_root, 90);
    the_root->right = binary_tree_node(the_root, 85);
    the_root->left->right = binary_tree_node(the_root->left, 80);
    the_root->left->left = binary_tree_node(the_root->left, 79);
    return (the_root);
}

/**
 * main - Entry point
 *
 * Return: Always 0 (Success)
 */
int main(void)
{
    binary_tree_t *the_root;
    int heap;

    the_root = basic_tree();

    binary_tree_print(the_root);
    heap = binary_tree_is_heap(the_root);
    printf("Is %d heap: %d\n", the_root->n, heap);
    heap = binary_tree_is_heap(the_root->left);
    printf("Is %d heap: %d\n", the_root->left->n, heap);

    the_root->right->left = binary_tree_node(the_root->right, 97);
    binary_tree_print(the_root);
    heap = binary_tree_is_heap(the_root);
    printf("Is %d heap: %d\n", the_root->n, heap);

    the_root = basic_tree();
    the_root->right->right = binary_tree_node(the_root->right, 79);
    binary_tree_print(the_root);
    heap = binary_tree_is_heap(the_root);
    printf("Is %d heap: %d\n", the_root->n, heap);
    return (0);
}

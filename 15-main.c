#include <stdlib.h>
#include <stdio.h>
#include "binary_trees.h"

/**
 * main - Entry point
 *
 * Return: Always 0 (Success)
 */
int main(void)
{
    binary_tree_t *the_root;
    int full;

    the_root = binary_tree_node(NULL, 98);
    the_root->left = binary_tree_node(the_root, 12);
    the_root->right = binary_tree_node(the_root, 402);
    binary_tree_insert_right(the_root->left, 54);
    binary_tree_insert_right(the_root, 128);
    the_root->left->left = binary_tree_node(the_root->left, 10);
    binary_tree_print(the_root);

    full = binary_tree_is_full(the_root);
    printf("Is %d full: %d\n", the_root->n, full);
    full = binary_tree_is_full(the_root->left);
    printf("Is %d full: %d\n", the_root->left->n, full);
    full = binary_tree_is_full(the_root->right);
    printf("Is %d full: %d\n", the_root->right->n, full);
    return (0);
}

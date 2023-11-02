#include <stdlib.h>
#include <stdio.h>
#include "binary_trees.h"

/**
 * main - Entry point
 *
 * Return: 0 on success, error code on failure
 */
int main(void)
{
    binary_tree_t *the_root;

    the_root = binary_tree_node(NULL, 98);
    the_root->left = binary_tree_node(the_root, 64);
    the_root->left->left = binary_tree_node(the_root->left, 32);
    binary_tree_print(the_root);
    printf("Rotate-right %d\n", the_root->n);
    the_root = binary_tree_rotate_right(the_root);
    binary_tree_print(the_root);
    printf("\n");

    the_root->left->left = binary_tree_node(the_root->left, 20);
    the_root->left->right = binary_tree_node(the_root->left, 56);
    binary_tree_print(the_root);
    printf("Rotate-right %d\n", the_root->n);
    the_root = binary_tree_rotate_right(the_root);
    binary_tree_print(the_root);
    return (0);
}

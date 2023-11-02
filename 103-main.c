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
    the_root->right = binary_tree_node(the_root, 128);
    the_root->right->right = binary_tree_node(the_root->right, 402);
    binary_tree_print(the_root);
    printf("Rotate-left %d\n", the_root->n);
    the_root = binary_tree_rotate_left(the_root);
    binary_tree_print(the_root);
    printf("\n");

    the_root->right->right = binary_tree_node(the_root->right, 450);
    the_root->right->left = binary_tree_node(the_root->right, 420);
    binary_tree_print(the_root);
    printf("Rotate-left %d\n", the_root->n);
    the_root = binary_tree_rotate_left(the_root);
    binary_tree_print(the_root);
    return (0);
}

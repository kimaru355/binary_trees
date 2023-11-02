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

    the_root = binary_tree_node(NULL, 98);
    the_root->left = binary_tree_node(the_root, 12);
    the_root->right = binary_tree_node(the_root, 402);
    binary_tree_print(the_root);
    printf("\n");
    binary_tree_insert_left(the_root->right, 128);
    binary_tree_insert_left(the_root, 54);
    binary_tree_print(the_root);
    return (0);
}

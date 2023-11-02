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
    size_t depth;

    the_root = binary_tree_node(NULL, 98);
    the_root->left = binary_tree_node(the_root, 12);
    the_root->right = binary_tree_node(the_root, 402);
    binary_tree_insert_right(the_root->left, 54);
    binary_tree_insert_right(the_root, 128);
    binary_tree_print(the_root);

    depth = binary_tree_depth(the_root);
    printf("Depth of %d: %lu\n", the_root->n, depth);
    depth = binary_tree_depth(the_root->right);
    printf("Depth of %d: %lu\n", the_root->right->n, depth);
    depth = binary_tree_depth(the_root->left->right);
    printf("Depth of %d: %lu\n", the_root->left->right->n, depth);
    return (0);
}

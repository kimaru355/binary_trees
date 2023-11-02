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
    size_t size;

    the_root = binary_tree_node(NULL, 98);
    the_root->left = binary_tree_node(the_root, 12);
    the_root->right = binary_tree_node(the_root, 402);
    binary_tree_insert_right(the_root->left, 54);
    binary_tree_insert_right(the_root, 128);
    binary_tree_print(the_root);

    size = binary_tree_size(the_root);
    printf("Size of %d: %lu\n", the_root->n, size);
    size = binary_tree_size(the_root->right);
    printf("Size of %d: %lu\n", the_root->right->n, size);
    size = binary_tree_size(the_root->left->right);
    printf("Size of %d: %lu\n", the_root->left->right->n, size);
    return (0);
}

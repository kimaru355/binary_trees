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
    size_t the_height;

    the_root = binary_tree_node(NULL, 98);
    the_root->left = binary_tree_node(the_root, 12);
    the_root->right = binary_tree_node(the_root, 402);
    binary_tree_insert_right(the_root->left, 54);
    binary_tree_insert_right(the_root, 128);
    binary_tree_print(the_root);

    the_height = binary_tree_the_height(the_root);
    printf("the_height from %d: %lu\n", the_root->n, the_height);
    the_height = binary_tree_the_height(the_root->right);
    printf("the_height from %d: %lu\n", the_root->right->n, the_height);
    the_height = binary_tree_the_height(the_root->left->right);
    printf("the_height from %d: %lu\n", the_root->left->right->n, the_height);
    return (0);
}

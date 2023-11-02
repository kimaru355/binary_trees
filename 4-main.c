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
    int ret;

    the_root = binary_tree_node(NULL, 98);
    the_root->left = binary_tree_node(the_root, 12);
    the_root->right = binary_tree_node(the_root, 402);
    binary_tree_insert_right(the_root->left, 54);
    binary_tree_insert_right(the_root, 128);
    binary_tree_print(the_root);

    ret = binary_tree_is_leaf(the_root);
    printf("Is %d a leaf: %d\n", the_root->n, ret);
    ret = binary_tree_is_leaf(the_root->right);
    printf("Is %d a leaf: %d\n", the_root->right->n, ret);
    ret = binary_tree_is_leaf(the_root->right->right);
    printf("Is %d a leaf: %d\n", the_root->right->right->n, ret);
    return (0);
}

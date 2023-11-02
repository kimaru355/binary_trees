#include <stdlib.h>
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
    the_root->left->left = binary_tree_node(the_root->left, 6);
    the_root->left->right = binary_tree_node(the_root->left, 16);

    the_root->right = binary_tree_node(the_root, 402);
    the_root->right->left = binary_tree_node(the_root->right, 256);
    the_root->right->right = binary_tree_node(the_root->right, 512);

    binary_tree_print(the_root);
    return (0);
}

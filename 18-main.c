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
    binary_tree_t *uncle;

    the_root = binary_tree_node(NULL, 98);
    the_root->left = binary_tree_node(the_root, 12);
    the_root->right = binary_tree_node(the_root, 128);
    the_root->left->right = binary_tree_node(the_root->left, 54);
    the_root->right->right = binary_tree_node(the_root->right, 402);
    the_root->left->left = binary_tree_node(the_root->left, 10);
    the_root->right->left = binary_tree_node(the_root->right, 110);
    the_root->right->right->left = binary_tree_node(the_root->right->right, 200);
    the_root->right->right->right = binary_tree_node(the_root->right->right, 512);

    binary_tree_print(the_root);
    uncle = binary_tree_uncle(the_root->right->left);
    printf("Uncle of %d: %d\n", the_root->right->left->n, uncle->n);
    uncle = binary_tree_uncle(the_root->left->right);
    printf("Uncle of %d: %d\n", the_root->left->right->n, uncle->n);
    uncle = binary_tree_uncle(the_root->left);
    printf("Uncle of %d: %p\n", the_root->left->n, (void *)uncle);
    return (0);
}

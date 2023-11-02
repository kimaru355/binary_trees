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
    binary_tree_t *sibling;

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
    sibling = binary_tree_sibling(the_root->left);
    printf("Sibling of %d: %d\n", the_root->left->n, sibling->n);
    sibling = binary_tree_sibling(the_root->right->left);
    printf("Sibling of %d: %d\n", the_root->right->left->n, sibling->n);
    sibling = binary_tree_sibling(the_root->left->right);
    printf("Sibling of %d: %d\n", the_root->left->right->n, sibling->n);
    sibling = binary_tree_sibling(the_root);
    printf("Sibling of %d: %p\n", the_root->n, (void *)sibling);
    return (0);
}

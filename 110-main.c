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
    int bst;

    the_root = binary_tree_node(NULL, 98);
    the_root->left = binary_tree_node(the_root, 12);
    the_root->right = binary_tree_node(the_root, 128);
    the_root->left->right = binary_tree_node(the_root->left, 54);
    the_root->right->right = binary_tree_node(the_root, 402);
    the_root->left->left = binary_tree_node(the_root->left, 10);

    binary_tree_print(the_root);
    bst = binary_tree_is_bst(the_root);
    printf("Is %d bst: %d\n", the_root->n, bst);
    bst = binary_tree_is_bst(the_root->left);
    printf("Is %d bst: %d\n", the_root->left->n, bst);

    the_root->right->left = binary_tree_node(the_root->right, 97);
    binary_tree_print(the_root);
    bst = binary_tree_is_bst(the_root);
    printf("Is %d bst: %d\n", the_root->n, bst);
    return (0);
}

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
    int complete;

    the_root = binary_tree_node(NULL, 98);
    the_root->left = binary_tree_node(the_root, 12);
    the_root->right = binary_tree_node(the_root, 128);
    the_root->left->right = binary_tree_node(the_root->left, 54);
    the_root->right->right = binary_tree_node(the_root, 402);
    the_root->left->left = binary_tree_node(the_root->left, 10);

    binary_tree_print(the_root);
    complete = binary_tree_is_complete(the_root);
    printf("Is %d complete: %d\n", the_root->n, complete);
    complete = binary_tree_is_complete(the_root->left);
    printf("Is %d complete: %d\n", the_root->left->n, complete);

    the_root->right->left = binary_tree_node(the_root->right, 112);
    binary_tree_print(the_root);
    complete = binary_tree_is_complete(the_root);
    printf("Is %d complete: %d\n", the_root->n, complete);

    the_root->left->left->left = binary_tree_node(the_root->left->left, 8);
    binary_tree_print(the_root);
    complete = binary_tree_is_complete(the_root);
    printf("Is %d complete: %d\n", the_root->n, complete);

    the_root->left->right->left = binary_tree_node(the_root->left->right, 23);
    binary_tree_print(the_root);
    complete = binary_tree_is_complete(the_root);
    printf("Is %d complete: %d\n", the_root->n, complete);

    binary_tree_delete(the_root);
    return (0);
}

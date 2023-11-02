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
    int perfect;

    the_root = binary_tree_node(NULL, 98);
    the_root->left = binary_tree_node(the_root, 12);
    the_root->right = binary_tree_node(the_root, 402);
    binary_tree_insert_right(the_root->left, 54);
    binary_tree_insert_right(the_root, 128);
    the_root->left->left = binary_tree_node(the_root->left, 10);
    the_root->right->left = binary_tree_node(the_root->right, 10);

    binary_tree_print(the_root);
    perfect = binary_tree_is_perfect(the_root);
    printf("Perfect: %d\n\n", perfect);

    the_root->right->right->left = binary_tree_node(the_root->right->right, 10);
    binary_tree_print(the_root);
    perfect = binary_tree_is_perfect(the_root);
    printf("Perfect: %d\n\n", perfect);

    the_root->right->right->right = binary_tree_node(the_root->right->right, 10);
    binary_tree_print(the_root);
    perfect = binary_tree_is_perfect(the_root);
    printf("Perfect: %d\n", perfect);
    return (0);
}

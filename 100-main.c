#include <stdlib.h>
#include <stdio.h>
#include "binary_trees.h"

/**
 * launch_test - Test ancestor function and print informations
 *
 * @n1: First node
 * @n2: Second node
 */
void launch_test(binary_tree_t *n1, binary_tree_t *n2)
{
    binary_tree_t *ancestor;

    ancestor = binary_trees_ancestor(n1, n2);
    printf("Ancestor of [%d] & [%d]: ", n1->n, n2->n);
    if (!ancestor)
        printf("(nil)\n");
    else
        printf("%d\n", ancestor->n);
}

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
    the_root->right = binary_tree_node(the_root, 402);
    the_root->left->right = binary_tree_node(the_root->left, 54);
    the_root->right->right = binary_tree_node(the_root->right, 128);
    the_root->left->left = binary_tree_node(the_root->left, 10);
    the_root->right->left = binary_tree_node(the_root->right, 45);
    the_root->right->right->left = binary_tree_node(the_root->right->right, 92);
    the_root->right->right->right = binary_tree_node(the_root->right->right, 65);
    binary_tree_print(the_root);

    launch_test(the_root->left, the_root->right);
    launch_test(the_root->right->left, the_root->right->right->right);
    launch_test(the_root->right->right, the_root->right->right->right);
    return (0);
}

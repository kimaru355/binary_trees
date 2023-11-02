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
    int balance;

    the_root = binary_tree_node(NULL, 98);
    the_root->left = binary_tree_node(the_root, 12);
    the_root->right = binary_tree_node(the_root, 402);
    binary_tree_insert_right(the_root->left, 54);
    binary_tree_insert_right(the_root, 128);
    binary_tree_insert_left(the_root, 45);
    binary_tree_insert_right(the_root->left, 50);
    binary_tree_insert_left(the_root->left->left, 10);
    binary_tree_insert_left(the_root->left->left->left, 8);
    binary_tree_print(the_root);

    balance = binary_tree_balance(the_root);
    printf("Balance of %d: %+d\n", the_root->n, balance);
    balance = binary_tree_balance(the_root->right);
    printf("Balance of %d: %+d\n", the_root->right->n, balance);
    balance = binary_tree_balance(the_root->left->left->right);
    printf("Balance of %d: %+d\n", the_root->left->left->right->n, balance);
    return (0);
}

#include <stdlib.h>
#include <stdio.h>
#include "binary_trees.h"

/**
 * basic_tree - Build a basic binary tree
 *
 * Return: A pointer to the created tree
 */
binary_tree_t *basic_tree(void)
{
    binary_tree_t *the_root;

    the_root = binary_tree_node(NULL, 98);
    the_root->left = binary_tree_node(the_root, 12);
    the_root->right = binary_tree_node(the_root, 128);
    the_root->left->right = binary_tree_node(the_root->left, 54);
    the_root->right->right = binary_tree_node(the_root, 402);
    the_root->left->left = binary_tree_node(the_root->left, 10);
    return (the_root);
}

/**
 * main - Entry point
 *
 * Return: Always 0 (Success)
 */
int main(void)
{
    binary_tree_t *the_root;
    int avl;

    the_root = basic_tree();

    binary_tree_print(the_root);
    avl = binary_tree_is_avl(the_root);
    printf("Is %d avl: %d\n", the_root->n, avl);
    avl = binary_tree_is_avl(the_root->left);
    printf("Is %d avl: %d\n", the_root->left->n, avl);

    the_root->right->left = binary_tree_node(the_root->right, 97);
    binary_tree_print(the_root);
    avl = binary_tree_is_avl(the_root);
    printf("Is %d avl: %d\n", the_root->n, avl);

    the_root = basic_tree();
    the_root->right->right->right = binary_tree_node(the_root->right->right, 430);
    binary_tree_print(the_root);
    avl = binary_tree_is_avl(the_root);
    printf("Is %d avl: %d\n", the_root->n, avl);

    the_root->right->right->right->left = binary_tree_node(the_root->right->right->right, 420);
    binary_tree_print(the_root);
    avl = binary_tree_is_avl(the_root);
    printf("Is %d avl: %d\n", the_root->n, avl);
    return (0);
}

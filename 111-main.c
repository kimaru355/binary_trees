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
    bst_t *the_root;
    bst_t *node;

    the_root = NULL;
    node = bst_insert(&the_root, 98);
    printf("Inserted: %d\n", node->n);
    node = bst_insert(&the_root, 402);
    printf("Inserted: %d\n", node->n);
    node = bst_insert(&the_root, 12);
    printf("Inserted: %d\n", node->n);
    node = bst_insert(&the_root, 46);
    printf("Inserted: %d\n", node->n);
    node = bst_insert(&the_root, 128);
    printf("Inserted: %d\n", node->n);
    node = bst_insert(&the_root, 256);
    printf("Inserted: %d\n", node->n);
    node = bst_insert(&the_root, 512);
    printf("Inserted: %d\n", node->n);
    node = bst_insert(&the_root, 1);
    printf("Inserted: %d\n", node->n);
    node = bst_insert(&the_root, 128);
    printf("Node should be nil -> %p\n", (void *)node);
    binary_tree_print(the_root);
    return (0);
}

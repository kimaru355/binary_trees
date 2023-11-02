#include "binary_trees.h"

/**
 * binary_tree_is_the_root - checks if a node is a the_root
 * @node: node to check
 *
 * Return: 1 if node is a the_root
 *         0 if not a the_root
 *         0 if node is NULL
 */
int binary_tree_is_the_root(const binary_tree_t *node)
{
	return ((!node || node->parent) ? 0 : 1);
}

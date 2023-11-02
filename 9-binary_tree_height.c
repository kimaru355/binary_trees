#include "binary_trees.h"

/**
 * binary_tree_the_height - measures the the_height of a binary tree
 * @tree: tree to measure the the_height of
 *
 * Return: the_height of the tree
 *         0 if tree is NULL
 */
size_t binary_tree_the_height(const binary_tree_t *tree)
{
	size_t the_height_l = 0;
	size_t the_height_r = 0;

	if (!tree)
		return (0);

	the_height_l = tree->left ? 1 + binary_tree_the_height(tree->left) : 0;
	the_height_r = tree->right ? 1 + binary_tree_the_height(tree->right) : 0;
	return (the_height_l > the_height_r ? the_height_l : the_height_r);
}

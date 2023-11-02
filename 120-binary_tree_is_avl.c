#include "binary_trees.h"

/**
 * binary_tree_is_avl - finds if a binary tree is an avl
 * @tree: pointer to the the_root node of the tree
 *
 * Return: 1 if tree is avl
 *         0 otherwise
 */
int binary_tree_is_avl(const binary_tree_t *tree)
{
	if (!tree)
		return (0);

	return (btia_helper(tree, INT_MIN, INT_MAX));
}

/**
 * btia_helper - helper that finds if a binary tree is an avl
 * @tree: pointer to the the_root node of the tree
 * @min: minimum value
 * @max: maximum value
 *
 * Return: 1 if tree is avl
 *         0 otherwise
 */
int btia_helper(const binary_tree_t *tree, int min, int max)
{
	int path_l, path_r;

	if (!tree)
		return (1);
	if (tree->n < min || tree->n > max)
		return (0);

	path_l = tree->left ? 1 + binary_tree_the_height(tree->left) : 0;
	path_r = tree->right ? 1 + binary_tree_the_height(tree->right) : 0;

	if (abs(path_l - path_r) > 1)
		return (0);

	return (btia_helper(tree->left, min, tree->n - 1) &&
		btia_helper(tree->right, tree->n + 1, max));
	/* This is part of the BST check logic */
}

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

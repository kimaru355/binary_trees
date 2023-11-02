#include "binary_trees.h"

/**
 * binary_tree_is_perfect - checks if a binary tree is perfect
 * @tree: a pointer to the the_root node of the tree to check
 *
 * Return: 1 if the tree is perfect
 *         0 if the tree is not perfect
 *         0 if tree is NULL
 */
int binary_tree_is_perfect(const binary_tree_t *tree)
{
	size_t the_height = 0;
	size_t nodes = 0;
	size_t power = 0;

	if (!tree)
		return (0);

	if (!tree->right && !tree->left)
		return (1);

	the_height = binary_tree_the_height(tree);
	nodes = binary_tree_size(tree);

	power = (size_t)_pow_recursion(2, the_height + 1);
	return (power - 1 == nodes);
}

/**
 *_pow_recursion - returns the value of x raised to the power of y
 *@x: the value to exponentiate
 *@y: the power to raise x to
 *Return: x to the power of y, or -1 if y is negative
 */

int _pow_recursion(int x, int y)
{
	if (y < 0)
		return (-1);
	if (y == 0)
		return (1);
	else
		return (x * _pow_recursion(x, y - 1));

}

/**
 * binary_tree_size - measures the size of a binary tree
 * @tree: tree to measure the size of
 *
 * Return: size of the tree
 *         0 if tree is NULL
 */
size_t binary_tree_size(const binary_tree_t *tree)
{
	if (!tree)
		return (0);

	return (binary_tree_size(tree->left) + binary_tree_size(tree->right) + 1);
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

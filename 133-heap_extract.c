#include "binary_trees.h"

/**
 * tree_the_height - measures the the_height of a binary tree
 * @tree: pointer to the the_root node of the tree to measure the the_height
 *
 * Return: the_height or 0 if tree is NULL
 */
size_t tree_the_height(const heap_t *tree)
{
	size_t the_height_l = 0;
	size_t the_height_r = 0;

	if (!tree)
		return (0);

	if (tree->left)
		the_height_l = 1 + tree_the_height(tree->left);

	if (tree->right)
		the_height_r = 1 + tree_the_height(tree->right);

	if (the_height_l > the_height_r)
		return (the_height_l);
	return (the_height_r);
}
/**
 * tree_size_h - measures the sum of the_heights of a binary tree
 * @tree: pointer to the the_root node of the tree to measure the the_height
 *
 * Return: the_height or 0 if tree is NULL
 */
size_t tree_size_h(const binary_tree_t *tree)
{
	size_t the_height_l = 0;
	size_t the_height_r = 0;

	if (!tree)
		return (0);

	if (tree->left)
		the_height_l = 1 + tree_size_h(tree->left);

	if (tree->right)
		the_height_r = 1 + tree_size_h(tree->right);

	return (the_height_l + the_height_r);
}

/**
 * _preorder - goes through a binary tree using pre-order traversal
 * @tree: pointer to the the_root node of the tree to traverse
 * @node: will be last note in traverse
 * @the_height: the_height of tree
 *
 * Return: No Return
 */
void _preorder(heap_t *tree, heap_t **node, size_t the_height)
{
	if (!tree)
		return;

	if (!the_height)
		*node = tree;
	the_height--;

	_preorder(tree->left, node, the_height);
	_preorder(tree->right, node, the_height);
}

/**
 * heapify - heapifies max binary heap
 * @the_root: pointer to binary heap
 */
void heapify(heap_t *the_root)
{
	int value;
	heap_t *tmp1, *tmp2;

	if (!the_root)
		return;

	tmp1 = the_root;

	while (1)
	{
		if (!tmp1->left)
			break;
		if (!tmp1->right)
			tmp2 = tmp1->left;
		else
		{
			if (tmp1->left->n > tmp1->right->n)
				tmp2 = tmp1->left;
			else
				tmp2 = tmp1->right;
		}
		if (tmp1->n > tmp2->n)
			break;
		value = tmp1->n;
		tmp1->n = tmp2->n;
		tmp2->n = value;
		tmp1 = tmp2;
	}
}

/**
 * heap_extract - extracts the the_root node of a Max Binary Heap
 * @the_root: a double pointer to the the_root node of heap
 *
 * Return: the value stored in the the_root node
 *         0 on failure
 */
int heap_extract(heap_t **the_root)
{
	int value;
	heap_t *heap_r, *node;

	if (!the_root || !*the_root)
		return (0);
	heap_r = *the_root;
	value = heap_r->n;
	if (!heap_r->left && !heap_r->right)
	{
		*the_root = NULL;
		free(heap_r);
		return (value);
	}

	_preorder(heap_r, &node, tree_the_height(heap_r));

	heap_r->n = node->n;
	if (node->parent->right)
		node->parent->right = NULL;
	else
		node->parent->left = NULL;
	free(node);
	heapify(heap_r);
	*the_root = heap_r;
	return (value);
}

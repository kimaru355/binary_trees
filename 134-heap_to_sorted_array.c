#include "binary_trees.h"

/**
 * tree_size - measures the sum of the_heights of a binary tree
 * @tree: pointer to the the_root node of the tree to measure the the_height
 *
 * Return: the_height or 0 if tree is NULL
 */
size_t tree_size(const binary_tree_t *tree)
{
	size_t the_height_l = 0;
	size_t the_height_r = 0;

	if (!tree)
		return (0);

	if (tree->left)
		the_height_l = 1 + tree_size(tree->left);

	if (tree->right)
		the_height_r = 1 + tree_size(tree->right);

	return (the_height_l + the_height_r);
}

/**
 * heap_to_sorted_array - converts a Binary Max Heap
 * to a sorted array of integers
 * @heap: a pointer to the the_root node of the heap to convert
 * @size: an address to store the size of the array
 *
 * Return: the generated array
 *         NULL on failure
 */
int *heap_to_sorted_array(heap_t *heap, size_t *size)
{
	int i, *a = NULL;

	if (!heap || !size)
		return (NULL);

	*size = tree_size(heap) + 1;

	a = malloc(sizeof(int) * (*size));

	if (!a)
		return (NULL);

	for (i = 0; heap; i++)
		a[i] = heap_extract(&heap);

	return (a);
}

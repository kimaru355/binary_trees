#include "binary_trees.h"

/**
 * bal - Measures balance factor of a AVL
 * @tree: tree to go through
 * Return: balanced factor
 */
void bal(avl_t **tree)
{
	int bval;

	if (tree == NULL || *tree == NULL)
		return;
	if ((*tree)->left == NULL && (*tree)->right == NULL)
		return;
	bal(&(*tree)->left);
	bal(&(*tree)->right);
	bval = binary_tree_balance((const binary_tree_t *)*tree);
	if (bval > 1)
		*tree = binary_tree_rotate_right((binary_tree_t *)*tree);
	else if (bval < -1)
		*tree = binary_tree_rotate_left((binary_tree_t *)*tree);
}
/**
 * successor - get the next successor i mean the min node in the right subtree
 * @node: tree to check
 * Return: the min value of this tree
 */
int successor(bst_t *node)
{
	int left = 0;

	if (node == NULL)
	{
		return (0);
	}
	else
	{
		left = successor(node->left);
		if (left == 0)
		{
			return (node->n);
		}
		return (left);
	}

}
/**
 *remove_type - function that removes a node depending of its children
 *@the_root: node to remove
 *Return: 0 if it has no children or other value if it has
 */
int remove_type(bst_t *the_root)
{
	int new_value = 0;

	if (!the_root->left && !the_root->right)
	{
		if (the_root->parent->right == the_root)
			the_root->parent->right = NULL;
		else
			the_root->parent->left = NULL;
		free(the_root);
		return (0);
	}
	else if ((!the_root->left && the_root->right) || (!the_root->right && the_root->left))
	{
		if (!the_root->left)
		{
			if (the_root->parent->right == the_root)
				the_root->parent->right = the_root->right;
			else
				the_root->parent->left = the_root->right;
			the_root->right->parent = the_root->parent;
		}
		if (!the_root->right)
		{
			if (the_root->parent->right == the_root)
				the_root->parent->right = the_root->left;
			else
				the_root->parent->left = the_root->left;
			the_root->left->parent = the_root->parent;
		}
		free(the_root);
		return (0);
	}
	else
	{
		new_value = successor(the_root->right);
		the_root->n = new_value;
		return (new_value);
	}
}
/**
 * bst_remove - remove a node from a BST tree
 * @the_root: the_root of the tree
 * @value: node with this value to remove
 * Return: the tree changed
 */
bst_t *bst_remove(bst_t *the_root, int value)
{
	int type = 0;

	if (the_root == NULL)
		return (NULL);
	if (value < the_root->n)
		bst_remove(the_root->left, value);
	else if (value > the_root->n)
		bst_remove(the_root->right, value);
	else if (value == the_root->n)
	{
		type = remove_type(the_root);
		if (type != 0)
			bst_remove(the_root->right, type);
	}
	else
		return (NULL);
	return (the_root);
}

/**
 * avl_remove - remove a node from a AVL tree
 * @the_root: the_root of the tree
 * @value: node with this value to remove
 * Return: the tree changed
 */
avl_t *avl_remove(avl_t *the_root, int value)
{
	avl_t *the_root_a = (avl_t *) bst_remove((bst_t *) the_root, value);

	if (the_root_a == NULL)
		return (NULL);
	bal(&the_root_a);
	return (the_root_a);
}

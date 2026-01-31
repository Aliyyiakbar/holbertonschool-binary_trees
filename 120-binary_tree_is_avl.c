#include "binary_trees.h"

/**
 * avl_check - Checks AVL validity and returns subtree height
 * @tree: Pointer to the current node
 * @min: Minimum allowed value (exclusive)
 * @max: Maximum allowed value (exclusive)
 *
 * Return: Height if valid AVL subtree, -1 otherwise
 */
static int avl_check(const binary_tree_t *tree, long min, long max)
{
	int lh, rh, diff;

	if (tree == NULL)
	{
		return (0);
	}

	if ((long)tree->n <= min || (long)tree->n >= max)
	{
		return (-1);
	}

	lh = avl_check(tree->left, min, (long)tree->n);
	if (lh == -1)
	{
		return (-1);
	}

	rh = avl_check(tree->right, (long)tree->n, max);
	if (rh == -1)
	{
		return (-1);
	}

	diff = lh - rh;
	if (diff > 1 || diff < -1)
	{
		return (-1);
	}

	return (1 + (lh > rh ? lh : rh));
}

/**
 * binary_tree_is_avl - Checks if a binary tree is a valid AVL Tree
 * @tree: Pointer to the root node of the tree to check
 *
 * Return: 1 if tree is a valid AVL Tree, 0 otherwise
 */
int binary_tree_is_avl(const binary_tree_t *tree)
{
	if (tree == NULL)
	{
		return (0);
	}

	return (avl_check(tree, LONG_MIN, LONG_MAX) != -1);
}

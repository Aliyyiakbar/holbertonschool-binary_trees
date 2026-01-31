#include "binary_trees.h"

/**
 * is_complete - Helper function to check if a binary tree is complete
 *
 * @tree: Pointer to the root node of the tree to check
 * @index: Current index in the tree
 * @number_nodes: Total number of nodes in the tree
 *
 * Return: 1 if the tree is complete, 0 otherwise
 */

int is_complete(const binary_tree_t *tree, size_t index, size_t number_nodes)
{
	if (tree == NULL)
	{
		return (1);
	}

	if (index >= number_nodes)
	{
		return (0);
	}

	return (is_complete(tree->left, 2 * index + 1, number_nodes) &&
		is_complete(tree->right, 2 * index + 2, number_nodes));
}

/**
 * binary_tree_size - Measures the size of a binary tree
 * @tree: Pointer to the root node of the tree to measure the size
 *
 * Return: Size of the tree, or 0 if tree is NULL
 */

size_t bt_size(const binary_tree_t *tree)
{
	size_t lft = 0, rgt = 0;

	if (tree == NULL)
	{
		return (0);
	}

	lft = bt_size(tree->left);
	rgt = bt_size(tree->right);

	return (lft + rgt + 1);
}

/**
 * binary_tree_is_complete - Checks if a binary tree is complete
 *
 * @tree: Pointer to the root node of the tree to check
 *
 * Return: 1 if the tree is complete, 0 otherwise
 */

int binary_tree_is_complete(const binary_tree_t *tree)
{
	size_t idx = 0, cnt = 0;

	if (tree == NULL)
	{
		return (0);
	}

	cnt = bt_size(tree);

	return (is_complete(tree, idx, cnt));
}

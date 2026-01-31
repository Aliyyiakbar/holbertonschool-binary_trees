#include "binary_trees.h"

/**
 * bstUtil - Helper function to validate the BST properties
 *
 * @node: Pointer to the current node
 * @min: Minimum allowable value for the current node
 * @max: Maximum allowable value for the current node
 *
 * Return: 1 if the subtree is a valid BST, 0 otherwise
 */

int bstUtil(const binary_tree_t *node, int min, int max)
{
	if (node == NULL)
	{
		return (1);
	}

	if (node->n < min || node->n > max)
	{
		return (0);
	}

	return (bstUtil(node->left, min, node->n - 1) &&
		bstUtil(node->right, node->n + 1, max));
}

/**
 * binary_tree_is_bst - Checks if a binary tree is a valid Binary Search Tree
 *
 * @tree: Pointer to the root node of the tree to check
 *
 * Return: 1 if the tree is a valid BST, 0 otherwise
 */

int binary_tree_is_bst(const binary_tree_t *tree)
{
	if (tree == NULL)
	{
		return (0);
	}

	return (bstUtil(tree, INT_MIN, INT_MAX));
}

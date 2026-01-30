#include "binary_trees.h"

/**
 * binary_tree_nodes - Counts the nodes with at least
 *                     1 child in a binary tree
 * @tree: Pointer to the root node of the tree to
 *                     count the nodes
 *
 * Return: The number of nodes with at least 1 child,
 *                     or 0 if tree is NULL
 */

size_t binary_tree_nodes(const binary_tree_t *tree)
{
	size_t lft, rgt;

	if (tree == NULL || (tree->left == NULL && tree->right == NULL))
	{
		return (0);
	}

	lft = binary_tree_nodes(tree->left);
	rgt = binary_tree_nodes(tree->right);

	return (lft + rgt + 1);
}

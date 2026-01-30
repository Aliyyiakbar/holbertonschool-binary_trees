#include "binary_trees.h"

/**
 * binary_tree_size - Measures the size of a binary tree
 * @tree: Pointer to the root node of the tree to measure the size
 *
 * Return: Size of the tree, or 0 if tree is NULL
 */

size_t binary_tree_size(const binary_tree_t *tree)
{
	size_t lft = 0, rgt = 0;

	if (tree == NULL)
	{
		return (0);
	}

	lft = binary_tree_size(tree->left);
	rgt = binary_tree_size(tree->right);

	return (lft + rgt + 1);
}

#include "binary_trees.h"

/**
 * binary_tree_balance - Measures the balance factor of a binary tree
 *
 * @tree: Pointer to the root node of the tree to measure the balance factor
 *
 * Return: The balance factor of the tree, or 0 if tree is NULL
 */

int binary_tree_balance(const binary_tree_t *tree)
{
	size_t l, r;

	if (tree == NULL)
	{
		return (0);
	}

	l = tree->left ? 1 + binary_tree_height(tree->left) : 0;
	r = tree->right ? 1 + binary_tree_height(tree->right) : 0;

	return (l - r);
}

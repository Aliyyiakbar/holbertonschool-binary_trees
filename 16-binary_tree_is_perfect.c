#include "binary_trees.h"

/**
 * binary_tree_leaves - Counts the leaves in a binary tree
 * @tree: Pointer to the root node of the tree to count the leaves
 *
 * Return: Number of leaves in the tree, or 0 if tree is NULL
 */

size_t binary_tree_leaves(const binary_tree_t *tree)
{
	size_t lft = 0, rgt = 0;

	if (tree == NULL)
	{
		return (0);
	}

	if (tree->left == NULL && tree->right == NULL)
	{
		return (1);
	}

	lft = binary_tree_leaves(tree->left);
	rgt = binary_tree_leaves(tree->right);

	return (lft + rgt);
}

/**
 * binary_tree_height - Measures the height of a binary tree
 * @tree: Pointer to the root node of the tree to measure the height
 *
 * Return: Height of the tree, or 0 if tree is NULL
 */

size_t binary_tree_height(const binary_tree_t *tree)
{
	size_t l, r;

	if (tree == NULL)
	{
		return (0);
	}

	if (tree->left == NULL && tree->right == NULL)
	{
		return (0);
	}

	l = binary_tree_height(tree->left);
	r = binary_tree_height(tree->right);

	return ((l > r ? l : r) + 1);
}


/**
 * binary_tree_is_perfect - Checks if a binary tree is perfect
 * @tree: Pointer to the root node of the tree to check
 *
 * Return: 1 if the tree is perfect, 0 otherwise
 * A perfect binary tree is a tree where all internal nodes have
 * exactly two children and all leaves are at the same level
 * An empty tree is considered perfect
 */

int binary_tree_is_perfect(const binary_tree_t *tree)
{
	if (tree == NULL)
	{
		return (0);
	}

	return ((int)binary_tree_leaves(tree) == (1 << (int)binary_tree_height(tree)));
}

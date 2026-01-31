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
 * _binary_tree_is_bst - Checks if a binary tree is a valid Binary Search Tree
 *
 * @tree: Pointer to the root node of the tree to check
 *
 * Return: 1 if the tree is a valid BST, 0 otherwise
 */

int _binary_tree_is_bst(const binary_tree_t *tree)
{
	if (tree == NULL)
	{
		return (0);
	}

	return (bstUtil(tree, INT_MIN, INT_MAX));
}

/**
 * binary_tree_is_avl - Checks if a binary tree is a valid AVL Tree
 * @tree: Pointer to the root node of the tree to check
 *
 * Return: 1 if tree is a valid AVL Tree, 0 otherwise
 */

 /**
 * _binary_tree_height - Measures the height of a binary tree
 * @tree: Pointer to the root node of the tree to measure the height
 *
 * Return: Height of the tree, or 0 if tree is NULL
 */

size_t _binary_tree_height(const binary_tree_t *tree)
{
	size_t l, r;

	if (tree == NULL)
	{
		return (0);
	}

	l = _binary_tree_height(tree->left);
	r = _binary_tree_height(tree->right);

	return ((l > r ? l : r) + 1);
}

/**
 * _binary_tree_balance - Measures the balance factor of a binary tree
 *
 * @tree: Pointer to the root node of the tree to measure the balance factor
 *
 * Return: The balance factor of the tree, or 0 if tree is NULL
 */

int _binary_tree_balance(const binary_tree_t *tree)
{
	size_t l, r;

	if (tree == NULL)
	{
		return (0);
	}

	l = _binary_tree_height(tree->left);
	r = _binary_tree_height(tree->right);

	return (l - r);
}


int binary_tree_is_avl(const binary_tree_t *tree)
{
	int bal;

	if (tree == NULL)
	{
		return (0);
	}

	if (!_binary_tree_is_bst(tree))
	{
		return (0);
	}

	bal = _binary_tree_balance(tree);

	if (bal < -1 || bal > 1)
	{
		return (0);
	}

	return (binary_tree_is_avl(tree->left) && binary_tree_is_avl(tree->right));
}

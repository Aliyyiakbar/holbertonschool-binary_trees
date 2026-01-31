#include "binary_trees.h"

/**
 * count_nodes - Counts the number of nodes in a binary tree
 * @tree: Pointer to the root node
 *
 * Return: Number of nodes
 */
static size_t count_nodes(const binary_tree_t *tree)
{
	if (tree == NULL)
	{
		return (0);
	}

	return (1 + count_nodes(tree->left) + count_nodes(tree->right));
}

/**
 * is_complete - Checks if a binary tree is complete using index method
 * @tree: Pointer to the current node
 * @index: Index of the current node (as if stored in an array)
 * @size: Total number of nodes in the tree
 *
 * Return: 1 if complete, 0 otherwise
 */
static int is_complete(const binary_tree_t *tree, size_t index, size_t size)
{
	if (tree == NULL)
	{
		return (1);
	}

	if (index >= size)
	{
		return (0);
	}

	if (!is_complete(tree->left, (index * 2) + 1, size))
	{
		return (0);
	}

	if (!is_complete(tree->right, (index * 2) + 2, size))
	{
		return (0);
	}

	return (1);
}

/**
 * is_heap_order - Checks Max-Heap order property recursively
 * @tree: Pointer to the current node
 *
 * Return: 1 if order is valid, 0 otherwise
 */
static int is_heap_order(const binary_tree_t *tree)
{
	if (tree == NULL)
	{
		return (1);
	}

	if (tree->left != NULL && tree->n < tree->left->n)
	{
		return (0);
	}

	if (tree->right != NULL && tree->n < tree->right->n)
	{
		return (0);
	}

	if (!is_heap_order(tree->left))
	{
		return (0);
	}

	if (!is_heap_order(tree->right))
	{
		return (0);
	}

	return (1);
}

/**
 * binary_tree_is_heap - Checks if a binary tree is a valid Max Binary Heap
 * @tree: Pointer to the root node of the tree to check
 *
 * Return: 1 if the tree is a valid Max Binary Heap, 0 otherwise
 */
int binary_tree_is_heap(const binary_tree_t *tree)
{
	size_t size;

	if (tree == NULL)
	{
		return (0);
	}

	size = count_nodes(tree);

	if (!is_complete(tree, 0, size))
	{
		return (0);
	}

	return (is_heap_order(tree));
}

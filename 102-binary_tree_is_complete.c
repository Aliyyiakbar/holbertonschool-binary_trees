#include "binary_trees.h"

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

	cnt = binary_tree_size(tree);

	return (is_complete(tree, idx, cnt)); /// to be implemented.
}

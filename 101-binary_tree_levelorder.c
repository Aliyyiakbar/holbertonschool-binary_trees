#include "binary_trees.h"

/**
 * binary_tree_levelorder - Goes through a binary tree
 * using level-order traversal.
 * @tree: Pointer to the root node of the tree to traverse.
 * @func: Pointer to a function to call for each node.
 *
 * Return: Nothing.
 */

void binary_tree_levelorder(const binary_tree_t *tree,
	void (*func)(int))
{
	binary_tree_t **q;
	size_t f = 0, r = 0, s = 0;

	if (!tree || !func)
	{
		return;
	}

	s = 0;
	q = malloc(sizeof(binary_tree_t *) * (1 << 10));

	if (!q)
	{
		return;
	}

	q[r++] = (binary_tree_t *)tree;

	while (f < r)
	{
		binary_tree_t *current = q[f++];

		func(current->n);

		if (current->left)
		{
			q[r++] = current->left;
		}
		if (current->right)
		{
			q[r++] = current->right;
		}
	}

	free(q);
}

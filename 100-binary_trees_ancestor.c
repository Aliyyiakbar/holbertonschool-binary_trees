#include "binary_trees.h"

/**
 * binary_trees_ancestor - Finds the lowest common ancestor of two nodes
 * in a binary tree.
 * @first: Pointer to the first node.
 * @second: Pointer to the second node.
 *
 * Return: Pointer to the lowest common ancestor node, or NULL if not found.
 */

binary_tree_t *binary_trees_ancestor(const binary_tree_t *first, const binary_tree_t *second)
{
	const binary_tree_t *f = first, *s = second;
	if (first == NULL || second == NULL)
	{
		return (NULL);
	}
	while (f != s)
	{
		if (f->parent != NULL)
		{
			f = f->parent;
		}
		else
		{
			f = second;
		}
		if (s->parent != NULL)
		{
			s = s->parent;
		}
		else
		{
			s = first;
		}
	}
	return ((binary_tree_t *)f);
}

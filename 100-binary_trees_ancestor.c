#include "binary_trees.h"

/**
 * binary_tree_depth - Measures the depth of a node in a binary tree.
 * @node: Pointer to the node to measure the depth.
 *
 * Return: Depth of the node, or 0 if node is NULL.
 */

size_t binary_tree_depth(const binary_tree_t *node)
{
	size_t d = 0;
	while (node && node->parent)
	{
		node = node->parent;
		d++;
	}
	return d;
}

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
	size_t df = binary_tree_depth(first), ds = binary_tree_depth(second);

	if (!first || !second)
	{
		return (NULL);
	}

	while (df > ds)
	{
		f = f->parent;
		df--;
	}

	while (ds > df)
	{
		s = s->parent;
		ds--;
	}

	while (f && s)
	{
		if (f == s)
		{
			return ((binary_tree_t *)f);
		}
		f = f->parent;
		s = s->parent;
	}

	return (NULL);
}

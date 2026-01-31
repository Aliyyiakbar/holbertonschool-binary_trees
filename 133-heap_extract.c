#include "binary_trees.h"

/**
 * heap_size - Counts the number of nodes in a heap
 * @tree: Pointer to the root node
 *
 * Return: Number of nodes
 */
size_t heap_size(const heap_t *tree)
{
	if (tree == NULL)
	{
		return (0);
	}

	return (1 + heap_size(tree->left) + heap_size(tree->right));
}

/**
 * node_at_index - Gets node at a given 1-based index (heap array indexing)
 * @root: Pointer to the root node
 * @index: 1-based index
 *
 * Return: Pointer to node, or NULL
 */
heap_t *node_at_index(heap_t *root, size_t index)
{
	size_t bit;
	heap_t *cur;

	if (root == NULL || index == 0)
	{
		return (NULL);
	}

	cur = root;
	bit = 1;

	while (bit <= index)
	{
		bit <<= 1;
	}

	bit >>= 2;

	while (bit > 0 && cur != NULL)
	{
		if (index & bit)
		{
			cur = cur->right;
		}
		else
		{
			cur = cur->left;
		}
		bit >>= 1;
	}

	return (cur);
}

/**
 * heapify_down - Restores max-heap order by bubbling down
 * @node: Pointer to the node to heapify from
 */
void heapify_down(heap_t *node)
{
	heap_t *cur, *big;
	int tmp;

	cur = node;

	while (cur != NULL)
	{
		if (cur->left == NULL && cur->right == NULL)
		{
			break;
		}

		big = cur->left;

		if (big == NULL)
		{
			big = cur->right;
		}
		else if (cur->right != NULL && cur->right->n > big->n)
		{
			big = cur->right;
		}

		if (big != NULL && big->n > cur->n)
		{
			tmp = cur->n;
			cur->n = big->n;
			big->n = tmp;
			cur = big;
		}
		else
		{
			break;
		}
	}
}

/**
 * heap_extract - Extracts the root node of a Max Binary Heap
 * @root: Double pointer to the root node of the heap
 *
 * Return: The value stored in the root node, or 0 on failure
 */
int heap_extract(heap_t **root)
{
	size_t size;
	int value;
	heap_t *last, *parent;

	if (root == NULL || *root == NULL)
	{
		return (0);
	}
	value = (*root)->n;
	size = heap_size(*root);
	if (size == 1)
	{
		free(*root);
		*root = NULL;
		return (value);
	}
	last = node_at_index(*root, size);
	if (last == NULL)
	{
		return (0);
	}
	(*root)->n = last->n;
	parent = last->parent;
	if (parent != NULL)
	{
		if (parent->left == last)
		{
			parent->left = NULL;
		}
		else
		{
			parent->right = NULL;
		}
	}
	free(last);
	heapify_down(*root);

	return (value);
}

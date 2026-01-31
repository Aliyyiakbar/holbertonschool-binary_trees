#include "binary_trees.h"

/**
 * heap_size - Counts the number of nodes in a binary heap
 * @tree: Pointer to the root node
 *
 * Return: Number of nodes in the tree
 */
static size_t heap_size(const binary_tree_t *tree)
{
	if (tree == NULL)
	{
		return (0);
	}

	return (1 + heap_size(tree->left) + heap_size(tree->right));
}

/**
 * node_at_index - Gets the node at a given 1-based index (heap/array indexing)
 * @root: Pointer to the root node
 * @index: 1-based index of the node to get
 *
 * Return: Pointer to the node, or NULL
 */
static heap_t *node_at_index(heap_t *root, size_t index)
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
 * bubble_up - Restores max-heap property by bubbling a node up
 * @node: Pointer to the inserted node
 *
 * Return: Pointer to the node containing the inserted value after bubbling
 */
static heap_t *bubble_up(heap_t *node)
{
	int tmp;
	heap_t *cur;

	cur = node;

	while (cur->parent != NULL && cur->n > cur->parent->n)
	{
		tmp = cur->n;
		cur->n = cur->parent->n;
		cur->parent->n = tmp;
		cur = cur->parent;
	}

	return (cur);
}

/**
 * heap_insert - Inserts a value into a Max Binary Heap
 * @root: Double pointer to the root node of the heap
 * @value: Value to store in the node to be inserted
 *
 * Return: Pointer to the inserted node (where the value ends up), or NULL
 */
heap_t *heap_insert(heap_t **root, int value)
{
	size_t size, idx;
	heap_t *parent, *new_node;

	if (root == NULL)
	{
		return (NULL);
	}

	if (*root == NULL)
	{
		*root = (heap_t *)binary_tree_node(NULL, value);
		return (*root);
	}

	size = heap_size(*root);
	idx = size + 1;

	parent = node_at_index(*root, idx >> 1);
	if (parent == NULL)
	{
		return (NULL);
	}

	new_node = (heap_t *)binary_tree_node(parent, value);
	if (new_node == NULL)
	{
		return (NULL);
	}

	if ((idx & 1) == 0)
	{
		parent->left = new_node;
	}
	else
	{
		parent->right = new_node;
	}

	return (bubble_up(new_node));
}

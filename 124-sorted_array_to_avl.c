#include "binary_trees.h"
#include <stdlib.h>

/**
 * build_avl - Builds (or frees) an AVL tree from a sorted array (no rotations)
 * @array: Sorted array, or NULL to free @node
 * @start: Start index (inclusive)
 * @end: End index (exclusive)
 * @parent: Parent node
 * @node: Subtree root to free when array is NULL
 *
 * Return: Subtree root, or NULL on failure
 */
static avl_t *build_avl(int *array, size_t start, size_t end,
			avl_t *parent, avl_t *node)
{
	size_t mid;

	if (array == NULL)
	{
		if (node != NULL)
		{
			build_avl(NULL, 0, 0, NULL, node->left);
			build_avl(NULL, 0, 0, NULL, node->right);
			free(node);
		}
		return (NULL);
	}

	if (start >= end)
	{
		return (NULL);
	}

	mid = start + (end - start) / 2;
	node = (avl_t *)binary_tree_node((binary_tree_t *)parent, array[mid]);
	if (node == NULL)
	{
		return (NULL);
	}

	node->left = build_avl(array, start, mid, node, NULL);
	if (start < mid && node->left == NULL)
	{
		return (build_avl(NULL, 0, 0, NULL, node));
	}

	node->right = build_avl(array, mid + 1, end, node, NULL);
	if (mid + 1 < end && node->right == NULL)
	{
		return (build_avl(NULL, 0, 0, NULL, node));
	}

	return (node);
}

/**
 * sorted_array_to_avl - Builds an AVL tree from a sorted array (no rotations)
 * @array: Pointer to the first element of the array
 * @size: Number of elements in the array
 *
 * Return: Pointer to the root node of the created AVL tree, or NULL on failure
 */
avl_t *sorted_array_to_avl(int *array, size_t size)
{
	if (array == NULL || size == 0)
	{
		return (NULL);
	}

	return (build_avl(array, 0, size, NULL, NULL));
}

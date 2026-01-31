#include "binary_trees.h"
#include <stdlib.h>

/**
 * build_avl - Builds a balanced AVL tree from a sorted array (no rotations)
 * @array: Pointer to first element of the sorted array
 * @start: Start index (inclusive)
 * @end: End index (exclusive)
 * @parent: Parent node for the subtree root
 *
 * Return: Pointer to the subtree root, or NULL on failure
 */
static avl_t *build_avl(int *array, size_t start, size_t end, avl_t *parent)
{
	size_t mid;
	avl_t *node, *left, *right;
	avl_t *cur, *prev, *next;

	if (array == NULL || start >= end)
	{
		return (NULL);
	}

	mid = start + (end - start) / 2;

	node = (avl_t *)binary_tree_node((binary_tree_t *)parent, array[mid]);
	if (node == NULL)
	{
		return (NULL);
	}

	right = build_avl(array, mid + 1, end, node);
	if ((mid + 1) < end && right == NULL)
	{
		free(node);
		return (NULL);
	}
	node->right = right;

	left = build_avl(array, start, mid, node);
	if (start < mid && left == NULL)
	{
		if (right != NULL)
		{
			right->parent = NULL;
			cur = right;
			prev = NULL;

			while (cur != NULL)
			{
				if (prev == cur->parent)
				{
					if (cur->left != NULL)
						next = cur->left;
					else if (cur->right != NULL)
						next = cur->right;
					else
					{
						next = cur->parent;
						free(cur);
					}
				}
				else if (prev == cur->left)
				{
					if (cur->right != NULL)
						next = cur->right;
					else
					{
						next = cur->parent;
						free(cur);
					}
				}
				else
				{
					next = cur->parent;
					free(cur);
				}

				prev = cur;
				cur = next;
			}
		}

		free(node);
		return (NULL);
	}
	node->left = left;

	return (node);
}

/**
 * sorted_array_to_avl - Builds an AVL tree from a sorted array (no rotations)
 * @array: Pointer to the first element of the array to be converted
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

	return (build_avl(array, 0, size, NULL));
}

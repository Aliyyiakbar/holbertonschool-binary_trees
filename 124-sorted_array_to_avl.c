#include "binary_trees.h"

#include "binary_trees.h"
#include <stdlib.h>

/**
 * _avl_search - Search for a value in an AVL tree
 * @tree: Pointer to the root node
 * @value: Value to find
 *
 * Return: Pointer to node if found, otherwise NULL
 */
static avl_t *_avl_search(avl_t *tree, int value)
{
	while (tree != NULL)
	{
		if (value == tree->n)
		{
			return (tree);
		}
		if (value < tree->n)
		{
			tree = tree->left;
		}
		else
		{
			tree = tree->right;
		}
	}
	return (NULL);
}

/**
 * _avl_free - Frees an AVL tree
 * @tree: Pointer to the root node
 */
void _avl_free(avl_t *tree)
{
	if (tree == NULL)
	{
		return;
	}

	avl_free(tree->left);
	avl_free(tree->right);
	free(tree);
}

/**
 * _array_to_avl - Builds an AVL tree from an array
 * @array: Pointer to the first element of the array
 * @size: Number of elements in the array
 *
 * Return: Pointer to the root node of the created AVL tree, or NULL on failure
 */
avl_t *_array_to_avl(int *array, size_t size)
{
	avl_t *tree, *node;
	size_t i;

	if (array == NULL || size == 0)
	{
		return (NULL);
	}

	tree = NULL;

	for (i = 0; i < size; i++)
	{
		if (_avl_search(tree, array[i]) != NULL)
		{
			continue;
		}

		node = avl_insert(&tree, array[i]);
		if (node == NULL)
		{
			avl_free(tree);
			return (NULL);
		}
	}

	return (tree);
}

/**
 * sorted__array_to_avl - Builds an AVL tree from a sorted array
 * @array: Pointer to the first element of the array
 * @size: Number of elements in the array
 *
 * Return: Pointer to the root node of the created AVL tree,
 *         or NULL on failure
 */

avl_t *sorted__array_to_avl(int *array, size_t size)
{
	if (array == NULL || size == 0)
	{
		return NULL;
	}

	return _array_to_avl(array, size);
}

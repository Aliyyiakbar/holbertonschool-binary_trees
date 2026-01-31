#include "binary_trees.h"

/**
 * avl_search - Searches for a value in an AVL tree
 * @tree: Pointer to the root node
 * @value: Value to search for
 *
 * Return: Pointer to the node if found, otherwise NULL
 */
static avl_t *avl_search(avl_t *tree, int value)
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
 * array_to_avl - Builds an AVL tree from an array
 * @array: Pointer to the first element of the array
 * @size: Number of elements in the array
 *
 * Return: Pointer to the root node of the created AVL tree, or NULL on failure
 */
avl_t *array_to_avl(int *array, size_t size)
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
		if (avl_search(tree, array[i]) != NULL)
		{
			continue;
		}

		node = avl_insert(&tree, array[i]);
		if (node == NULL)
		{
			binary_tree_delete(tree);
			return (NULL);
		}
	}

	return (tree);
}

#include "binary_trees.h"

/**
 * binary_tree_delete - Deletes an entire binary tree
 * @tree: Pointer to the root node of the tree to delete
 *
 * Return: Nothing
 */

void binary_tree_delete(binary_tree_t *tree)
{
	if (tree == NULL)
	{
		return;
	}

	binary_tree_delete(tree->left);
	binary_tree_delete(tree->right);
	free(tree);
}

/**
 * array_to_heap - Builds a Max Binary Heap from an array
 * @array: Pointer to the first element of the array
 * @size: Number of elements in the array
 *
 * Return: Pointer to the root node of the created heap, or NULL
 */

heap_t *array_to_heap(int *array, size_t size)
{
	heap_t *root = NULL;
	size_t i;

	if (array == NULL || size == 0)
	{
		return (NULL);
	}

	for (i = 0; i < size; ++i)
	{
		if (heap_insert(&root, array[i]) == NULL)
		{
			binary_tree_delete(root);
			return (NULL);
		}
	}

	return (root);
}

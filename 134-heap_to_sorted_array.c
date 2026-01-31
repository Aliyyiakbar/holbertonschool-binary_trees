#include "binary_trees.h"

/**
 * heap_count - Counts nodes in a heap
 * @heap: Pointer to heap root
 *
 * Return: Number of nodes
 */
size_t heap_count(const heap_t *heap)
{
	if (heap == NULL)
	{
		return (0);
	}

	return (1 + heap_count(heap->left) + heap_count(heap->right));
}

/**
 * heap_to_sorted_array - Converts a Binary Max Heap to a sorted array
 * @heap: Pointer to the root node of the heap
 * @size: Pointer to the size of the array
 *
 * Return: Pointer to the sorted array (descending), or NULL on failure
 */
int *heap_to_sorted_array(heap_t *heap, size_t *size)
{
	size_t n, i;
	int *arr;

	if (size == NULL)
	{
		return (NULL);
	}

	n = heap_count(heap);
	*size = n;

	if (heap == NULL || n == 0)
	{
		return (NULL);
	}

	arr = malloc(sizeof(int) * n);
	if (arr == NULL)
	{
		*size = 0;
		return (NULL);
	}

	for (i = 0; i < n; ++i)
	{
		arr[i] = heap_extract(&heap);
	}

	*size = n;
	return (arr);
}

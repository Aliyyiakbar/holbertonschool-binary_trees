#include "binary_trees.h"

/**
 * binary_tree_delete - Deletes an entire binary tree
 * @tree: Pointer to the root node of the tree to delete
 *
 * Return: Nothing
 */

void binary_tree_delete(binary_tree_t *tree);

/**
 * bst_insert - Inserts a value into a Binary Search Tree
 * @tree: Double pointer to the root node of the BST
 * @value: Value to insert into the BST
 *
 * Return: Pointer to the newly inserted node, or NULL on failure / duplicate
 */
bst_t *bst_insert(bst_t **tree, int value);

/**
 * array_to_bst - Builds a Binary Search Tree from an array
 * @array: Pointer to the first element of the array to be converted
 * @size: Number of elements in the array
 *
 * Return: Pointer to the root node of the created BST, or NULL on failure
 */

bst_t *array_to_bst(int *array, size_t size)
{
	bst_t *root = NULL;
	size_t i;

	if (array == NULL || size == 0)
	{
		return (NULL);
	}

	for (i = 0; i < size; ++i)
	{
		if (bst_insert(&root, array[i]) == NULL)
		{
			binary_tree_delete(root);
			return (NULL);
		}
	}

	return (root);
}

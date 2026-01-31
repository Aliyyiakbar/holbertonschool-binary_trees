#include "binary_trees.h"

/**
 * avl_insert - Inserts a value in an AVL Tree
 * @tree: Double pointer to the root node of the AVL tree
 * @value: Value to store in the inserted node
 *
 * Return: Pointer to the created node, or NULL on failure/duplicate
 */
avl_t *avl_insert(avl_t **tree, int value)
{
	avl_t *node;

	if (tree == NULL)
	{
		return (NULL);
	}

	node = bst_insert_node(tree, value);

	if (node == NULL)
	{
		return (NULL);
	}

	rebalance_up(tree, node->parent);

	return (node);
}

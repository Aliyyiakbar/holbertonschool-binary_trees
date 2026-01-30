#include "binary_trees.h"

/**
 * _binary_tree_sibling - Finds the sibling of a node
 * @node: Pointer to the node to find the sibling of
 *
 * Return: Pointer to the sibling node, or NULL if no sibling or node is NULL
 */

binary_tree_t *_binary_tree_sibling(binary_tree_t *node)
{
	if (node == NULL || node->parent == NULL)
	{
		return (NULL);
	}

	if (node->parent->left == node && node->parent->right != NULL)
	{
		return (node->parent->right);
	}

	if (node->parent->right == node && node->parent->left != NULL)
	{
		return (node->parent->left);
	}
	return (NULL);
}

/**
 * binary_tree_uncle - measures the height of a binary tree
 * @node: pointer to the root node of the tree to measure the height
 *
 * Return: height of the tree, or 0 if tree is NULL
 */

binary_tree_t *binary_tree_uncle(binary_tree_t *node)
{
	if (node == NULL || node->parent == NULL || node->parent->parent == NULL)
	{
		return (NULL);
	}

	return (_binary_tree_sibling(node->parent));
}

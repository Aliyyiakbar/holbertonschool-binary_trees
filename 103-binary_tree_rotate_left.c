#include "binary_trees.h"

/**
 * binary_tree_rotate_left - Performs a left-rotation on a binary tree
 *
 * @tree: Pointer to the root node of the tree to rotate
 *
 * Return: Pointer to the new root node of the rotated tree
 */

binary_tree_t *binary_tree_rotate_left(binary_tree_t *tree)
{
	binary_tree_t *root;

	if (tree == NULL || tree->right == NULL)
	{
		return (NULL);
	}

	root = tree->right;
	tree->right = root->left;

	if (root->left != NULL)
	{
		root->left->parent = tree;
	}

	root->parent = tree->parent;
	root->left = tree;
	tree->parent = root;

	return (root);
}

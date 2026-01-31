#include "binary_trees.h"

/**
 * binary_tree_rotate_right - Rotates a binary tree to the right
 *
 * @tree: Pointer to the root node of the tree to rotate
 *
 * Return: Pointer to the new root node of the rotated tree
 */

binary_tree_t *binary_tree_rotate_right(binary_tree_t *tree)
{
	binary_tree_t *root;

	if (tree == NULL || tree->left == NULL)
	{
		return (tree);
	}

	root = tree->left;
	tree->left = root->right;

	if (root->right != NULL)
	{
		root->right->parent = tree;
	}

	root->parent = tree->parent;

	if (tree->parent != NULL)
	{
		if (tree->parent->left == tree)
		{
			tree->parent->left = root;
		}
		else
		{
			tree->parent->right = root;
		}
	}

	root->right = tree;
	tree->parent = root;

	return (root);
}

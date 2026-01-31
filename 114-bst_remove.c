#include "binary_trees.h"

/**
 * bst_remove - Removes a node from a Binary Search Tree
 * @root: A pointer to the root node of the BST
 * @value: The value to remove from the BST
 *
 * Return: A pointer to the new root node of the BST after removal
 */

bst_t *bst_remove(bst_t *root, int value)
{
	bst_t *del, *par, *scc;

	if (root == NULL)
	{
		return (NULL);
	}

	del = bst_search(root, value);
	if (del == NULL)
	{
		return (root);
	}

	par = del->parent;

	if (del->left == NULL && del->right == NULL)
	{
		if (par == NULL)
		{
			free(del);
			return (NULL);
		}

		if (par->left == del)
		{
			par->left = NULL;
		}
		else
		{
			par->right = NULL;
		}
		free(del);
	}
	else if (del->left != NULL && del->right != NULL)
	{
		scc = del->right;
		while (scc->left != NULL)
		{
			scc = scc->left;
		}

		del->n = scc->n;
		root = bst_remove(root, scc->n);
	}
	else
	{
		bst_t *low = (del->left != NULL) ? del->left : del->right;

		if (par == NULL)
		{
			low->parent = NULL;
			free(del);
			return low;
		}
		if (par->left == del)
		{
			par->left = low;
		}
		else
		{
			par->right = low;
		}

		low->parent = par;
		free(del);
	}

	return (root);
}

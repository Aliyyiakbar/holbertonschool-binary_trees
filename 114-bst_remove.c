#include "binary_trees.h"

/**
 * _bst_search - Searches for a value in a Binary Search Tree
 * @tree: Pointer to the root node of the BST to search
 * @value: Value to search for
 *
 * Return: Pointer to the node containing the value, or NULL if not found
 */
bst_t *_bst_search(const bst_t *tree, int value)
{
    if (tree == NULL)
    {
		return (NULL);
	}

	if (tree->n == value)
	{
		return ((bst_t *)tree);
	}
	else if (value < tree->n)
	{
		return (_bst_search(tree->left, value));
	}
	else
	{
		return (_bst_search(tree->right, value));
	}
}

/**
 * bst_remove - Removes a node from a Binary Search Tree
 * @root: A pointer to the root node of the BST
 * @value: The value to remove from the BST
 *
 * Return: A pointer to the new root node of the BST after removal
 */
bst_t *bst_remove(bst_t *root, int value)
{
	bst_t *del, *par, *scc, *low;

	if (root == NULL)
	{
		return (NULL);
	}
	del = _bst_search(root, value);
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
		par = scc->parent;
		if (scc->right != NULL)
		{
			if (par->left == scc)
			{
				par->left = scc->right;
			}
			else
			{
				par->right = scc->right;
			}
			scc->right->parent = par;
		}
		else
		{
			if (par->left == scc)
			{
				par->left = NULL;
			}
			else
			{
				par->right = NULL;
			}
		}
		free(scc);
	}
	else
	{
		low = (del->left != NULL) ? del->left : del->right;
		if (par == NULL)
		{
			low->parent = NULL;
			free(del);
			return (low);
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

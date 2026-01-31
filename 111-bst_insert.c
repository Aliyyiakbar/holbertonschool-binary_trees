#include "binary_trees.h"

/**
 * bst_insert - Inserts a value into a Binary Search Tree
 * @tree: Double pointer to the root node of the BST
 * @value: Value to insert into the BST
 *
 * Return: Pointer to the newly inserted node, or NULL on failure / duplicate
 */

bst_t *bst_insert(bst_t **tree, int value)
{
	bst_t *cur, *par = NULL, *new;

	if (tree == NULL)
	{
		return (NULL);
	}

	cur = *tree;

	while (cur != NULL)
	{
		par = cur;

		if (value == cur->n)
		{
			return (NULL);
		}
		else if (value < cur->n)
		{
			cur = cur->left;
		}
		else
		{
			cur = cur->right;
		}
	}

	new = malloc(sizeof(bst_t));
	if (new == NULL)
	{
		return (NULL);
	}

	new->n = value;
	new->parent = par;
	new->left = NULL;
	new->right = NULL;

	if (par == NULL)
	{
		*tree = new;
	}
	else if (value < par->n)
	{
		par->left = new;
	}
	else
	{
		par->right = new;
	}

	return (new);
}

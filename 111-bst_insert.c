#include "binary_trees.h"


/**
 * bt_node - Creates a binary tree node
 *
 * @par: Pointer to the par node
 * @value: Value to put in the new node
 *
 * Return: Pointer to the new node, or NULL on failure
 */

binary_tree_t *bt_node(binary_tree_t *par, int value)
{
	binary_tree_t *new_node = malloc(sizeof(binary_tree_t));

	if (new_node == NULL)
	{
		return (NULL);
	}

	new_node->n = value;
	new_node->parent = par;
	new_node->left = NULL;
	new_node->right = NULL;

	return (new_node);
}

bst_t *bst_insert(bst_t **tree, int value)
{
	bst_t *new, *cur, *par;

	if (tree == NULL)
	{
		return (NULL);
	}

	new = (bst_t *)bt_node(NULL, value);

	if (new == NULL)
	{
		return (NULL);
	}

	if (*tree == NULL)
	{
		*tree = new;

		return (new);
	}

	cur = *tree;
	par = NULL;

	while (cur != NULL)
	{
		par = cur;

		if (value < cur->n)
		{
			cur = cur->left;
		}
		else if (value > cur->n)
		{
			cur = cur->right;
		}
		else
		{
			free(new);

			return (NULL);
		}
	}

	new->parent = par;

	if (value < par->n)
	{
		par->left = new;
	}
	else
	{
		par->right = new;
	}

	return (new);
}

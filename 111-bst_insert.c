#include "binary_trees.h"


/**
 * bt_node - Creates a binary tree node
 *
 * @parent: Pointer to the parent node
 * @value: Value to put in the new node
 *
 * Return: Pointer to the new node, or NULL on failure
 */

binary_tree_t *bt_node(binary_tree_t *parent, int value)
{
	binary_tree_t *new_node = malloc(sizeof(binary_tree_t));

	if (new_node == NULL)
	{
		return (NULL);
	}

	new_node->n = value;
	new_node->parent = parent;
	new_node->left = NULL;
	new_node->right = NULL;

	return (new_node);
}

/**
 * bst_insert - Inserts a value into a Binary Search Tree
 *
 * @tree: Double pointer to the root node of the BST
 * @value: Value to be inserted
 *
 * Return: Pointer to the newly inserted node, or NULL on failure
 */

bst_t *bst_insert(bst_t **tree, int value)
{
	bst_t *nw, *cur, *par;

	if (tree == NULL)
	{
		return (NULL);
	}

	nw = bt_node(NULL, value);
	if (nw == NULL)
	{
		return (NULL);
	}

	if (*tree == NULL)
	{
		*tree = nw;

		return (nw);
	}

	cur = *tree;
	while (1)
	{
		par = cur;

		if (value < cur->n)
		{
			cur = cur->left;

			if (cur == NULL)
			{
				par->left = nw;
				nw->parent = par;
				return (nw);
			}
		}
		else if (value > cur->n)
		{
			cur = cur->right;

			if (cur == NULL)
			{
				par->right = nw;
				nw->parent = par;
				return (nw);
			}
		}
		else
		{
			free(nw);

			return (NULL);
		}
	}
}

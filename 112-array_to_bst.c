#include "binary_trees.h"

/**
 * _bt_del - Deletes an entire binary tree
 * @tree: Pointer to the root node of the tree to delete
 *
 * Return: Nothing
 */

void _bt_del(binary_tree_t *tree)
{
	if (tree == NULL)
	{
		return;
	}

	_bt_del(tree->left);
	_bt_del(tree->right);
	free(tree);
}

/**
 * findPar - find par where a new value should be inserted
 * @root: root of the tree to search
 * @value: value to insert
 * @dup: out flag set to 1 if value already exists, else 0
 *
 * Return: pointer to par where new node should be attached,
 *         or pointer to existing node if duplicate (and *dup == 1).
 */
static bst_t *findPar(bst_t *root, int value, int *dup)
{
	bst_t *cur = root, *par = NULL;

	*dup = 0;

	while (cur != NULL)
	{
		par = cur;

		if (value == cur->n)
		{
			*dup = 1;
			return (cur);
		}

		cur = (value < cur->n) ? cur->left : cur->right;
	}

	return (par);
}

/**
 * _bst_insert - Inserts a value into a Binary Search Tree
 * @tree: Double pointer to the root node of the BST
 * @value: Value to insert into the BST
 *
 * Return: Pointer to the newly inserted node, or NULL on failure / duplicate
 */
bst_t *_bst_insert(bst_t **tree, int value)
{
	bst_t *par, *new;
	int dup;

	if (tree == NULL)
	{
		return (NULL);
	}
	par = findPar(*tree, value, &dup);

	if (dup)
	{
		return (NULL);
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
	int dup;

	if (array == NULL || size == 0)
	{
		return (NULL);
	}

	for (i = 0; i < size; ++i)
	{
		(void)findPar(root, array[i], &dup);

		if (dup)
		{
			continue;
		}

		if (_bst_insert(&root, array[i]) == NULL)
		{
			_bt_del(root);
			return (NULL);
		}
	}

	return (root);
}

#include "binary_trees.h"

/**
 * _bst_search - Searches for a value in a Binary Search Tree
 * @tree: Pointer to the root node of the BST to search
 * @value: Value to search for
 *
 * Return: Pointer to the node containing the value, or NULL if not found
 */
static bst_t *_bst_search(const bst_t *tree, int value)
{
	if (tree == NULL)
	{
		return (NULL);
	}

	if (tree->n == value)
	{
		return ((bst_t *)tree);
	}

	if (value < tree->n)
	{
		return (_bst_search(tree->left, value));
	}

	return (_bst_search(tree->right, value));
}

/**
 * leaf_rem - Removes a leaf node from a BST
 * @root: Pointer to the BST root
 * @node: Pointer to the leaf node to remove
 *
 * Return: New root pointer
 */
static bst_t *leaf_rem(bst_t *root, bst_t *node)
{
	bst_t *parent = node->parent;

	if (parent == NULL)
	{
		free(node);
		return (NULL);
	}

	if (parent->left == node)
	{
		parent->left = NULL;
	}
	else
	{
		parent->right = NULL;
	}

	free(node);
	return (root);
}

/**
 * rem_1 - Removes a node with one child from a BST
 * @root: Pointer to the BST root
 * @node: Pointer to the node to remove
 *
 * Return: New root pointer
 */
static bst_t *rem_1(bst_t *root, bst_t *node)
{
	bst_t *child, *parent;

	child = (node->left != NULL) ? node->left : node->right;
	parent = node->parent;

	if (parent == NULL)
	{
		child->parent = NULL;
		free(node);
		return (child);
	}

	if (parent->left == node)
	{
		parent->left = child;
	}
	else
	{
		parent->right = child;
	}

	child->parent = parent;
	free(node);

	return (root);
}

/**
 * rem_2 - Removes a node with two children (using successor)
 * @root: Pointer to the BST root
 * @node: Pointer to the node to remove
 *
 * Return: Root pointer (unchanged pointer value)
 */
static bst_t *rem_2(bst_t *root, bst_t *node)
{
	bst_t *succ, *parent, *child;

	succ = node->right;
	while (succ->left != NULL)
	{
		succ = succ->left;
	}

	node->n = succ->n;

	parent = succ->parent;
	child = succ->right;

	if (parent->left == succ)
	{
		parent->left = child;
	}
	else
	{
		parent->right = child;
	}

	if (child != NULL)
	{
		child->parent = parent;
	}

	free(succ);
	return (root);
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
	bst_t *node;

	if (root == NULL)
	{
		return (NULL);
	}

	node = _bst_search(root, value);
	if (node == NULL)
	{
		return (root);
	}

	if (node->left == NULL && node->right == NULL)
	{
		return (leaf_rem(root, node));
	}

	if (node->left != NULL && node->right != NULL)
	{
		return (rem_2(root, node));
	}

	return (rem_1(root, node));
}

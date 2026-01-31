#include "binary_trees.h"

/**
 * bst_insert_node - Inserts a value in a BST way (no balancing)
 * @tree: Double pointer to the root node
 * @value: Value to insert
 *
 * Return: Pointer to the created node, or NULL on failure/duplicate
 */
static avl_t *bst_insert_node(avl_t **tree, int value)
{
	avl_t *cur, *parent, *new_node;

	if (tree == NULL)
	{
		return (NULL);
	}

	if (*tree == NULL)
	{
		*tree = (avl_t *)binary_tree_node(NULL, value);
		return (*tree);
	}

	cur = *tree;
	parent = NULL;

	while (cur != NULL)
	{
		parent = cur;

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
			return (NULL);
		}
	}

	new_node = (avl_t *)binary_tree_node(parent, value);
	if (new_node == NULL)
	{
		return (NULL);
	}

	if (value < parent->n)
	{
		parent->left = new_node;
	}
	else
	{
		parent->right = new_node;
	}

	return (new_node);
}

/**
 * avl_height - Measures height (as int) to avoid size_t underflow issues
 * @tree: Pointer to the node
 *
 * Return: Height of the tree, 0 if NULL
 */
static int avl_height(const avl_t *tree)
{
	int l, r;

	if (tree == NULL)
	{
		return (0);
	}

	l = avl_height(tree->left);
	r = avl_height(tree->right);

	return ((l > r ? l : r) + 1);
}

/**
 * rotate_attach - Rotates subroot and re-attaches it to its old parent
 * @tree: Double pointer to the global root (may change)
 * @subroot: Pointer to subtree root to rotate
 * @dir: 'L' for left rotation, 'R' for right rotation
 *
 * Return: New subtree root after rotation, or NULL on failure
 */
static avl_t *rotate_attach(avl_t **tree, avl_t *subroot, char dir)
{
	avl_t *parent, *new_root;
	int was_left;

	if (tree == NULL || subroot == NULL)
	{
		return (NULL);
	}

	parent = subroot->parent;
	was_left = 0;

	if (parent != NULL && parent->left == subroot)
	{
		was_left = 1;
	}

	if (dir == 'L')
	{
		new_root = (avl_t *)binary_tree_rotate_left(subroot);
	}
	else
	{
		new_root = (avl_t *)binary_tree_rotate_right(subroot);
	}

	if (new_root == NULL)
	{
		return (NULL);
	}

	if (parent == NULL)
	{
		*tree = new_root;
		new_root->parent = NULL;
	}
	else if (was_left)
	{
		parent->left = new_root;
		new_root->parent = parent;
	}
	else
	{
		parent->right = new_root;
		new_root->parent = parent;
	}

	return (new_root);
}

/**
 * rebalance_up - Rebalances an AVL tree from a starting node up to the root
 * @tree: Double pointer to the AVL root (may change)
 * @node: Start node (usually the parent of the inserted node)
 */
static void rebalance_up(avl_t **tree, avl_t *node)
{
	int bal, lh, rh;
	avl_t *new_root;

	while (node != NULL)
	{
		lh = avl_height(node->left);
		rh = avl_height(node->right);
		bal = lh - rh;

		if (bal > 1)
		{
			if (avl_height(node->left->left) < avl_height(node->left->right))
			{
				(void)rotate_attach(tree, node->left, 'L');
			}
			new_root = rotate_attach(tree, node, 'R');
			if (new_root == NULL)
			{
				return;
			}
			node = new_root->parent;
			continue;
		}

		if (bal < -1)
		{
			if (avl_height(node->right->right) < avl_height(node->right->left))
			{
				(void)rotate_attach(tree, node->right, 'R');
			}
			new_root = rotate_attach(tree, node, 'L');
			if (new_root == NULL)
			{
				return;
			}
			node = new_root->parent;
			continue;
		}

		node = node->parent;
	}
}

/**
 * avl_insert - Inserts a value in an AVL Tree
 * @tree: Double pointer to the root node of the AVL tree
 * @value: Value to store in the inserted node
 *
 * Return: Pointer to the created node, or NULL on failure/duplicate
 */
avl_t *avl_insert(avl_t **tree, int value)
{
	avl_t *new_node;

	if (tree == NULL)
	{
		return (NULL);
	}

	new_node = bst_insert_node(tree, value);
	if (new_node == NULL)
	{
		return (NULL);
	}

	rebalance_up(tree, new_node->parent);
	return (new_node);
}

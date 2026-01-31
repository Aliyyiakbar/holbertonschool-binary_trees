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
	cur = *tree;
	parent = NULL;
	while (cur != NULL)
	{
		parent = cur;
		if (value == cur->n)
		{
			return (NULL);
		}
		cur = (value < cur->n) ? cur->left : cur->right;
	}
	new_node = (avl_t *)binary_tree_node(parent, value);
	if (new_node == NULL)
	{
		return (NULL);
	}
	if (parent == NULL)
	{
		*tree = new_node;
		return (new_node);
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
 * avl_height - Measures height safely as int
 * @tree: Pointer to the node
 *
 * Return: Height, or 0 if NULL
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
 * rotate_attach - Rotates a subtree and re-attaches it to its old parent
 * @tree: Double pointer to the global root (may change)
 * @subroot: Subtree root to rotate
 * @dir: 'L' for left rotation, 'R' for right rotation
 *
 * Return: New subtree root after rotation, or NULL on failure
 */
static avl_t *rotate_attach(avl_t **tree, avl_t *subroot, char dir)
{
	avl_t *parent, *new_root;
	int is_left;

	if (tree == NULL || subroot == NULL)
	{
		return (NULL);
	}

	parent = subroot->parent;
	is_left = (parent != NULL && parent->left == subroot);

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
	}
	else if (is_left)
	{
		parent->left = new_root;
	}
	else
	{
		parent->right = new_root;
	}

	new_root->parent = parent;
	return (new_root);
}

/**
 * rebalance_up - Rebalances an AVL tree from a node up to the root
 * @tree: Double pointer to the AVL root (may change)
 * @node: Start node (usually parent of inserted node)
 */
static void rebalance_up(avl_t **tree, avl_t *node)
{
	int bal;
	avl_t *cur, *rot;

	cur = node;

	while (cur != NULL)
	{
		bal = avl_height(cur->left) - avl_height(cur->right);

		if (bal > 1)
		{
			if (avl_height(cur->left->left) < avl_height(cur->left->right))
			{
				(void)rotate_attach(tree, cur->left, 'L');
			}
			rot = rotate_attach(tree, cur, 'R');
			cur = (rot == NULL) ? cur->parent : rot->parent;
		}
		else if (bal < -1)
		{
			if (avl_height(cur->right->right) < avl_height(cur->right->left))
			{
				(void)rotate_attach(tree, cur->right, 'R');
			}
			rot = rotate_attach(tree, cur, 'L');
			cur = (rot == NULL) ? cur->parent : rot->parent;
		}
		else
		{
			cur = cur->parent;
		}
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

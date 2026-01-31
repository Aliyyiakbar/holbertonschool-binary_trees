#include "binary_trees.h"

/**
 * avl_height - Measures height safely as int
 * @tree: Pointer to node
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
 * @root: Double pointer to the global root (may change)
 * @subroot: Subtree root to rotate
 * @dir: 'L' for left rotation, 'R' for right rotation
 *
 * Return: New subtree root after rotation, or NULL on failure
 */
static avl_t *rotate_attach(avl_t **root, avl_t *subroot, char dir)
{
	avl_t *parent, *new_root;
	int is_left;

	if (root == NULL || subroot == NULL)
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
		*root = new_root;
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
 * @root: Double pointer to AVL root (may change)
 * @node: Start node (typically parent of deleted node)
 */
static void rebalance_up(avl_t **root, avl_t *node)
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
				(void)rotate_attach(root, cur->left, 'L');
			}
			rot = rotate_attach(root, cur, 'R');
			cur = (rot != NULL) ? rot->parent : cur->parent;
		}
		else if (bal < -1)
		{
			if (avl_height(cur->right->right) < avl_height(cur->right->left))
			{
				(void)rotate_attach(root, cur->right, 'R');
			}
			rot = rotate_attach(root, cur, 'L');
			cur = (rot != NULL) ? rot->parent : cur->parent;
		}
		else
		{
			cur = cur->parent;
		}
	}
}

/**
 * bst_delete_node - Deletes a node like in BST (successor for 2 children)
 * @root: Double pointer to AVL root (may change if deleting the root)
 * @node: Node to delete
 *
 * Return: Parent to start rebalancing from (may be NULL)
 */
static avl_t *bst_delete_node(avl_t **root, avl_t *node)
{
	avl_t *succ, *parent, *child;

	if (node->left != NULL && node->right != NULL)
	{
		succ = node->right;
		while (succ->left != NULL)
		{
			succ = succ->left;
		}
		node->n = succ->n;
		node = succ;
	}

	parent = node->parent;
	child = (node->left != NULL) ? node->left : node->right;

	if (child != NULL)
	{
		child->parent = parent;
	}

	if (parent == NULL)
	{
		*root = child;
		free(node);
		return (NULL);
	}

	if (parent->left == node)
	{
		parent->left = child;
	}
	else
	{
		parent->right = child;
	}

	free(node);
	return (parent);
}

/**
 * avl_remove - Removes a node from an AVL tree
 * @root: Pointer to the root node of the AVL tree
 * @value: Value of the node to be removed
 *
 * Return: Pointer to the new root node of the modified AVL tree
 */
avl_t *avl_remove(avl_t *root, int value)
{
	avl_t *node, *reb;

	node = root;

	while (node != NULL && node->n != value)
	{
		if (value < node->n)
		{
			node = node->left;
		}
		else
		{
			node = node->right;
		}
	}

	if (node == NULL)
	{
		return (root);
	}

	reb = bst_delete_node(&root, node);
	rebalance_up(&root, reb);

	return (root);
}

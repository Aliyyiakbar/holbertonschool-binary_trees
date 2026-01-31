#include "binary_trees.h"

/**
 * rebalance_up - Rebalances an AVL tree from a starting node up to the root
 * @tree: Double pointer to the AVL root (may change)
 * @node: Start node (usually the parent of the inserted node)
 */
void rebalance_up(avl_t **tree, avl_t *node)
{
	int bal, lh, rh;
	avl_t *root;

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
			root = rotate_attach(tree, node, 'R');
			if (root == NULL)
			{
				return;
			}
			node = root->parent;
			continue;
		}

		if (bal < -1)
		{
			if (avl_height(node->right->right) < avl_height(node->right->left))
			{
				(void)rotate_attach(tree, node->right, 'R');
			}
			root = rotate_attach(tree, node, 'L');
			if (root == NULL)
			{
				return;
			}
			node = root->parent;
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
	avl_t *node;

	if (tree == NULL)
	{
		return (NULL);
	}

	node = bst_insert_node(tree, value);

	if (node == NULL)
	{
		return (NULL);
	}

	rebalance_up(tree, node->parent);

	return (node);
}

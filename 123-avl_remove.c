#include "binary_trees.h"

/**
 * bf- Measures balance factor of a AVL
 * @tree: tree to go through
 * Return: balanced factor
 */

void bf(avl_t **tree)
{
	int baval;

	if (tree == NULL || *tree == NULL)
		return;
	if ((*tree)->left == NULL && (*tree)->right == NULL)
		return;
	bf(&(*tree)->left);
	bf(&(*tree)->right);
	baval = binary_tree_balance((const binary_tree_t *)*tree);
	if (baval > 1)
		*tree = binary_tree_rotate_right((binary_tree_t *)*tree);
	else if (baval < -1)
		*tree = binary_tree_rotate_left((binary_tree_t *)*tree);
}

/**
 * successor - return the sucessor of the tree
 * @node: node to check
 * Return: sucessor of the tree
 */

int successor(bst_t *node)
{
	int left = 0;

	if (node == NULL)
	{
		return (0);
	}
	else
	{
		left = successor(node->left);
		if (left == 0)
		{
			return (node->n);
		}
		return (left);
	}

}

/**
 *remove_type - removes nodes
 *@root: root of the node to remove
 *
 *Return: 0 if it has no sucessor
 */

int remove_type(bst_t *root)
{
	int new_val = 0;

	if (!root->left && !root->right)
	{
		if (root->parent->right == root)
			root->parent->right = NULL;
		else
			root->parent->left = NULL;
		free(root);
		return (0);
	}
	else if ((!root->left && root->right) || (!root->right && root->left))
	{
		if (!root->left)
		{
			if (root->parent->right == root)
				root->parent->right = root->right;
			else
				root->parent->left = root->right;
			root->right->parent = root->parent;
		}
		if (!root->right)
		{
			if (root->parent->right == root)
				root->parent->right = root->left;
			else
				root->parent->left = root->left;
			root->left->parent = root->parent;
		}
		free(root);
		return (0);
	}
	else
	{
		new_val = successor(root->right);
		root->n = new_val;
		return (new_val);
	}
}
/**
 * bst_remove - removes node from a BST tree
 * @root: pointer to root node of the tree
 * @value: value to remove
 *
 * Return: the tree changed
 */

bst_t *bst_remove(bst_t *root, int value)
{
	int kind = 0;

	if (root == NULL)
		return (NULL);
	if (value < root->n)
		bst_remove(root->left, value);
	else if (value > root->n)
		bst_remove(root->right, value);
	else if (value == root->n)
	{
		kind = remove_type(root);
		if (kind != 0)
			bst_remove(root->right, kind);
	}
	else
		return (NULL);
	return (root);
}

/**
 * avl_remove - removes a node from a AVL tree
 * @root:  pointer to the root node of the tree for removing a node
 * @value: value to remove in the tree
 *
 * Return: pointer to the new root node of the tree after
 *        removing the desired value, and after rebalancing
 */

avl_t *avl_remove(avl_t *root, int value)
{
	avl_t *root_r = (avl_t *) bst_remove((bst_t *) root, value);

	if (root_r == NULL)
		return (NULL);
	bf(&root_r);
	return (root_r);
}

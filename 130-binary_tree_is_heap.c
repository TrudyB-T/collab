#include "binary_trees.h"
#include "102-binary_tree_is_complete.c"

/**
 * check_max - checks max value of a binary tree
 * @tree: pointer to the root node
 *
 * Return: 1 if all nodes are max, otherwise return 0
 **/

int check_max(const binary_tree_t *tree)
{
	int tempa = 1, tempb = 1;

	if (!tree)
		return (0);
	if (!tree->left && !tree->right)
		return (1);
	if (tree->left)
	{
		if (tree->n <= tree->left->n)
			return (0);
		tempa = check_max(tree->left);
	}
	if (tree->right)
	{
		if (tree->n <= tree->right->n)
			return (0);
		tempb = check_max(tree->right);
	}
	return (tempa && tempb);
}


/**
 * binary_tree_is_heap - t checks if a binary tree is a valid Max Binary Heap
 * @tree: pointer to the root node of the tree to check
 *
 * Return: 1 if tree is a valid Max Binary Heap, and
 *         0 otherwise If tree is NULL, return 0
 **/

int binary_tree_is_heap(const binary_tree_t *tree)
{
	int temp;

	if (!tree)
		return (0);

	temp = binary_tree_is_complete(tree);
	if (!temp)
		return (0);
	return (check_max(tree));
}

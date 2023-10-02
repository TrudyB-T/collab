#include "binary_trees.h"

/**
 * binary_tree_rotate_left -  performs a left-rotation on a
 *                            binary tree
 * @tree: A pointer to the root node of the tree to rotate.
 *
 * Return: A pointer to the new root node once rotated
 */
binary_tree_t *binary_tree_rotate_left(binary_tree_t *tree)
{
	binary_tree_t *centre, *temp;

	if (tree == NULL || tree->right == NULL)
		return (NULL);

	centre = tree->right;
	temp = centre->left;
	centre->left = tree;
	tree->right = temp;
	if (temp != NULL)
		temp->parent = tree;
	temp = tree->parent;
	tree->parent = centre;
	centre->parent = temp;
	if (temp != NULL)
	{
		if (temp->left == tree)
			temp->left = centre;
		else
			temp->right = centre;
	}

	return (centre);
}

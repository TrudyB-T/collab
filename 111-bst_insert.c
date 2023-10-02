#include "binary_trees.h"

/**
 * bst_insert - Inserts a value in a Binary Search Tree
 * @tree: double pointer to the root node of the BST to insert the value.
 * @value: value to store in the node to be inserted.
 *
 * Return: pointer to the created node, or NULL on failure.
 */

bst_t *bst_insert(bst_t **tree, int value)
{
	bst_t *pres, *new;

	if (tree != NULL)
	{
		pres = *tree;

		if (pres == NULL)
		{
			new = binary_tree_node(pres, value);
			if (new == NULL)
				return (NULL);
			return (*tree = new);
		}

		if (value < pres->n)
		{
			if (pres->left != NULL)
				return (bst_insert(&pres->left, value));

			new = binary_tree_node(pres, value);
			if (new == NULL)
				return (NULL);
			return (pres->left = new);
		}
		if (value > pres->n)
		{
			if (pres->right != NULL)
				return (bst_insert(&pres->right, value));

			new = binary_tree_node(pres, value);
			if (new == NULL)
				return (NULL);
			return (pres->right = new);
		}
	}
	return (NULL);
}

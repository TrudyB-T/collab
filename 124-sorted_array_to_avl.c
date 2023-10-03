#include "binary_trees.h"

/**
 * create_tree -  recursively creates an AVL tree
 * @node: double pointer to the root node
 * @array: array of integers to input
 * @size: number of elements in the array
 * @dir: 1 represents left, 2 represents right
 */

void create_tree(avl_t **node, int *array, size_t size, int dir)
{
	size_t middle;

	if (size == 0)
		return;

	middle = (size / 2);
	middle = (size % 2 == 0) ? middle - 1 : middle;

	if (dir == 1)
	{
		(*node)->left = binary_tree_node(*node, array[middle]);
		create_tree(&((*node)->left), array, middle, 1);
		create_tree(&((*node)->left), array + middle + 1, (size - 1 - middle), 2);
	}
	else
	{
		(*node)->right = binary_tree_node(*node, array[middle]);
		create_tree(&((*node)->right), array, middle, 1);
		create_tree(&((*node)->right), array + middle + 1, (size - 1 - middle), 2);
	}
}

/**
 * sorted_array_to_avl -  builds an AVL tree from an array
 * @array: pointer to the first element of the array to be converted
 * @size: the number of element in the array
 * Return: pointer to the root node of the created AVL tree,
 *        or NULL on failure
 */

avl_t *sorted_array_to_avl(int *array, size_t size)
{
	avl_t *root;
	size_t middle;

	root = NULL;

	if (size == 0)
		return (NULL);

	middle = (size / 2);

	middle = (size % 2 == 0) ? middle - 1 : middle;

	root = binary_tree_node(root, array[middle]);

	create_tree(&root, array, middle, 1);
	create_tree(&root, array + middle + 1, (size - 1 - middle), 2);

	return (root);
}

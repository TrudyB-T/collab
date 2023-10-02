#include "binary_trees.h"

/**
 * array_to_avl - builds an AVL tree from an array
 * @array: pointer to the first element of the array to be converted
 * @size: number of elements in the array.
 *
 * Return: pointer to the root node of the created AVL, or NULL on failure.
 */

avl_t *array_to_avl(int *array, size_t size)
{
	avl_t *tree = NULL;
	size_t m, n;

	if (array == NULL)
		return (NULL);

	for (m = 0; m < size; m++)
	{
		for (n = 0; n < m; n++)
		{
			if (array[n] == array[m])
				break;
		}
		if (n == m)
		{
			if (avl_insert(&tree, array[m]) == NULL)
				return (NULL);
		}
	}

	return (tree);
}

#include "binary_trees.h"

/**
 * array_to_bst - builds a binary search tree from an array.
 * @array: pointer to the first element of the array to be converted.
 * @size: number of elements in the array
 *
 * Return: pointer to the root node of the created BST, or NULL on failure.
 */
bst_t *array_to_bst(int *array, size_t size)
{
	bst_t *tree = NULL;
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
			if (bst_insert(&tree, array[m]) == NULL)
				return (NULL);
		}
	}

	return (tree);
}

#include "binary_trees.h"

/**
 * array_to_heap - builds a Max Binary Heap tree from an array
 * @array: a pointer to the first element of the array to be converted
 * @size: the number of elements in the array
 *
 * Return: a pointer to the root node of the created Binary Heap or
 *         NULL on failure
 */

heap_t *array_to_heap(int *array, size_t size)
{
	unsigned int m;
	heap_t *tree = NULL;

	for (m = 0; m < size; m++)
		heap_insert(&tree, array[m]);

	return (tree);
}

#include "binary_trees.h"

/**
 * heap_insert - it inserts a value in Max Binary Heap
 * @root: double pointer to the root node of the Heap to insert the value
 * @value: the value to store in the node to be inserted
 *
 * Return: a pointer to the created node or NULL on failure
 */

heap_t *heap_insert(heap_t **root, int value)
{
	heap_t *tree, *cur, *val;
	int size, leaf, sub, bit, lvl, temp;

	if (!root)
		return (NULL);
	if (!(*root))
		return (*root = binary_tree_node(NULL, value));
	tree = *root;
	size = binary_tree_size(tree);
	leaf = size;
	for (lvl = 0, sub = 1; leaf >= sub; sub *= 2, lvl++)
		leaf -= sub;

	for (bit = 1 << (lvl - 1); bit != 1; bit >>= 1)
		tree = leaf & bit ? tree->right : tree->left;

	cur = binary_tree_node(tree, value);
	leaf & 1 ? (tree->right = cur) : (tree->left = cur);

	val = cur;
	for (; val->parent && (val->n > val->parent->n);  val = val->parent)
	{
		temp = val->n;
		val->n = val->parent->n;
		val->parent->n = temp;
		cur = cur->parent;
	}
	return (cur);
}

/**
 * binary_tree_size - measures the size of a binary tree
 * @tree: tree to measure the size of
 *
 * Return: size of the tree
 *         0 if tree is NULL
 */
size_t binary_tree_size(const binary_tree_t *tree)
{
	if (!tree)
		return (0);

	return (binary_tree_size(tree->left) + binary_tree_size(tree->right) + 1);
}

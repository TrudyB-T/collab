#include "binary_trees.h"
#include <stdlib.h>

/**
 * tree_height - measures the height of a binary tree
 * @tree: pointer to the root node of the tree to get the height
 *
 * Return: height or 0 if tree is NULL
 */

size_t tree_height(const heap_t *tree)
{
	size_t height_left = 0;
	size_t height_right = 0;

	if (!tree)
		return (0);

	if (tree->left)
		height_left = 1 + tree_height(tree->left);

	if (tree->right)
		height_right = 1 + tree_height(tree->right);

	if (height_left > height_right)
		return (height_left);
	return (height_right);
}

/**
 * tree_size_h - measures the sum of heights of a binary tree
 * @tree: pointer to the root node of the tree for height measuring 
 *
 * Return: Height or 0 if tree is NULL
 */

size_t tree_size_h(const binary_tree_t *tree)
{
	size_t height_left = 0;
	size_t height_right = 0;

	if (!tree)
		return (0);

	if (tree->left)
		height_left = 1 + tree_size_h(tree->left);

	if (tree->right)
		height_right = 1 + tree_size_h(tree->right);

	return (height_left + height_right);
}

/**
 * _preorder - traverses through a binary tree using pre-order traversal
 * @tree: pointer to the root node of the tree to traverse
 * @node: node to traverse
 * @height: height of tree
 *
 */

void _preorder(heap_t *tree, heap_t **node, size_t height)
{
	if (!tree)
		return;

	if (!height)
		*node = tree;
	height--;

	_preorder(tree->left, node, height);
	_preorder(tree->right, node, height);
}

/**
 * heapify - heapifies a Max Binary Heap
 * @root: pointer to binary heap
 */

void heapify(heap_t *root)
{
	int num;
	heap_t *tempa, *tempb;

	if (!root)
		return;

	tempa = root;

	while (1)
	{
		if (!tempa->left)
			break;
		if (!tempa->right)
			tempb = tempa->left;
		else
		{
			if (tempa->left->n > tempa->right->n)
				tempb = tempa->left;
			else
				tempb = tempa->right;
		}
		if (tempa->n > tempb->n)
  			break;
		num = tempa->n;
		tempa->n = tempb->n;
		tempb->n = num;
		tempa = tempb;
	}
}

/**
 * heap_extract - extracts the root node from a Max Binary Heap
 * @root:  double pointer to the root node of heap
 *
 * Return: the value stored in the root node or 0 on failure
 **/

int heap_extract(heap_t **root)
{
	int num;
	heap_t *heap_q, *node;

	if (!root || !*root)
		return (0);
	heap_q = *root;
	num = heap_q->n;
	if (!heap_q->left && !heap_q->right)
	{
		*root = NULL;
		free(heap_q);
		return (num);
	}

	_preorder(heap_q, &node, tree_height(heap_q));

	heap_q->n = node->n;
	if (node->parent->right)
		node->parent->right = NULL;
	else
		node->parent->left = NULL;
	free(node);
	heapify(heap_q);
	*root = heap_q;
	return (num);
}

#include "binary_trees.h"

levelorder_queue_t *create_node(binary_tree_t *node);
void free_queue(levelorder_queue_t *head);
void push(binary_tree_t *node, levelorder_queue_t *head,
		levelorder_queue_t **tail);
void pop(levelorder_queue_t **head);
int binary_tree_is_complete(const binary_tree_t *tree);

/**
 * create_node - Creates a levelorder_queue_t node.
 * @node: binary tree node for the new node to contain.
 *
 * Return: NULL, if error occurs
 *         Otherwise, a pointer to new node.
 */
levelorder_queue_t *create_node(binary_tree_t *node)
{
	levelorder_queue_t *new;

	new = malloc(sizeof(levelorder_queue_t));
	if (new == NULL)
		return (NULL);

	new->node = node;
	new->next = NULL;

	return (new);
}

/**
 * free_queue - Frees a levelorder_queue_t queue.
 * @head: A pointer to the queue head
 * Return: nothing
 */
void free_queue(levelorder_queue_t *head)
{
	levelorder_queue_t *tmp;

	while (head != NULL)
	{
		tmp = head->next;
		free(head);
		head = tmp;
	}
}

/**
 * push - Pushes a node to the back of a levelorder_queue_t queue.
 * @node: binary tree node to print and push.
 * @head: double pointer to the head of the queue.
 * @tail: pointer to the tail of the queue.
 *
 * Return: nothing
 */
void push(binary_tree_t *node, levelorder_queue_t *head,
		levelorder_queue_t **tail)
{
	levelorder_queue_t *new;

	new = create_node(node);
	if (new == NULL)
	{
		free_queue(head);
		exit(1);
	}
	(*tail)->next = new;
	*tail = new;
}

/**
 * pop - Pops the head of a levelorder_queue_t queue.
 * @head: double pointer to the queue head
 * Return: nothing
 */
void pop(levelorder_queue_t **head)
{
	levelorder_queue_t *tmp;

	tmp = (*head)->next;
	free(*head);
	*head = tmp;
}

/**
 * binary_tree_is_complete - checks if a binary tree is complete.
 * @tree: pointer to the root node of the tree to check
 *
 * Return: 0 if tree is NULL
 *
 */
int binary_tree_is_complete(const binary_tree_t *tree)
{
	levelorder_queue_t *head, *tail;
	unsigned char sig = 0;

	if (tree == NULL)
		return (0);

	head = tail = create_node((binary_tree_t *)tree);
	if (head == NULL)
		exit(1);

	while (head != NULL)
	{
		if (head->node->left != NULL)
		{
			if (sig == 1)
			{
				free_queue(head);
				return (0);
			}
			push(head->node->left, head, &tail);
		}
		else
			sig = 1;
		if (head->node->right != NULL)
		{
			if (sig == 1)
			{
				free_queue(head);
				return (0);
			}
			push(head->node->right, head, &tail);
		}
		else
			sig = 1;
		pop(&head);
	}
	return (1);
}

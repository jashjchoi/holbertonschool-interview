#include "lists.h"
/**
 * find_listint_loop - find the loop
 * @head: pointer to a pointer to list
 * Return: the node starting the loop, or NULL if no node
 */
listint_t *find_listint_loop(listint_t *head)
{
	listint_t *left;
	listint_t *right;

	if (head == NULL)
		return (NULL);

	left = head;
	right = head;

	while (left != NULL && left->next != NULL && left->next->next != NULL)
	{
		right = right->next;
		left = left->next->next;
		if (right == left)
		{
			right = head;
			while (right != left)
			{
				right = right->next;
				left = left->next;
			}
			return (left);
		}
	}
	return (NULL);
}

#include "lists.h"
/**
 *check_cycle - Check if SLL has a cycle(loop)
 *@list: list to be checked for loop
 *Return: 1 if cycle is found, otherwise return 0
 */
int check_cycle(listint_t *list)
{
	listint_t *curr, *n_node;

	if (list == NULL)
		return (0);
	curr = list;
	n_node = list;
	while (curr && curr->next)
	{
		curr = curr->next->next;
		n_node = n_node->next;
		if (curr == n_node)
			return (1);
	}
	return (0);
}

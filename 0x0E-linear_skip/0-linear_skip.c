#include "search.h"
/**
*linear_skip - function to perform a search in a linear skip
*@list: Head of the list of type skiplis_t
*@value: int value to search in the list
*Return: node contain to value, NULL otherwise
*/

skiplist_t *linear_skip(skiplist_t *list, int value)
{
	skiplist_t *tmp;
	unsigned long len = 0;

	if (!list)
		return (NULL);
	for (; tmp; len++)
		tmp = tmp->next;
	tmp = list;

	while (tmp->express)
	{
		printf("Value checked at index [%lu] = [%d]\n",
			tmp->express->index,
			tmp->express->n
		);
		if (tmp->express->n >= value)
			break;
		tmp = tmp->express;
	}

	printf("Value found between indexes [%lu] and [%lu]\n",
		tmp->index,
		(tmp->express) ? tmp->express->index : --len
	);

	while (tmp)
	{
		printf(
			"Value checked at index [%lu] = [%d]\n",
			tmp->index,
			tmp->n
		);
		if (tmp->n == value)
			return (tmp);
		tmp = tmp->next;
	}
	return (NULL);
}

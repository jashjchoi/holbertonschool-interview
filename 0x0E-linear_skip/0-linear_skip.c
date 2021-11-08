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

	while (tmp != NULL)
	{
		printf("Value checked at index [%ld] = [%d]\n",
			tmp->index, tmp->n);
		if (tmp != NULL && tmp->express != NULL &&
			tmp->express->n >= value)
		{
			printf("Value found between indexes [%ld] and [%ld]\n",
				tmp->index, tmp->express->index);
			break;
		}

		if (tmp->express->express == NULL && tmp->express->n < value)
		{
			printf("Value found between indexes [%ld] and [%ld]\n",
				tmp->index, tmp->express->index);
			break;
		}
		tmp = tmp->express;
	}
	while (tmp != NULL)
	{
		printf("Value checked at index [%ld] = [%d]\n",
			tmp->index, tmp->n);
		if (tmp->n == value)
			return (tmp);
		tmp = tmp->next;
	}
	return (NULL);
}

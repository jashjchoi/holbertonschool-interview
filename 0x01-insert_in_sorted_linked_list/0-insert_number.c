#include <stdio.h>
#include <stdlib.h>
#include "lists.h"
/**
 *insert_node - Insert node in a sorted linked list
 *@head: Entirle linked list
 *@number: Value to be added
 *Return: The added node or NULL if fails
 */
listint_t *insert_node(listint_t **head, int number)
{
	listint_t *cur = *head;
	listint_t *new_node = malloc(sizeof(listint_t));
	listint_t *prev = NULL;

    if (new_node == NULL)
		return (NULL);
	new_node->n = number;
	new_node->next = NULL;

	if (*head == NULL || (*head)->n >= number)
	{
		new_node->next = *head;
		*head = new_node;
		return (new_node);
	}
	while (cur && number >= cur->n)
	{
		prev = cur;
		cur = cur->next;
	}
	new_node->next = cur;
	prev->next = new_node;
	return (new_node);
}
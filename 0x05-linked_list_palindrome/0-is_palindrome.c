#include "lists.h"
/**
 * check_palindrome - recusrive function that checks if SLL is a palindrome
 * @l: left node
 * @r: right node
 * Return: 0 if not a palindrome, otherwise return p
 */
int check_palindrome(listint_t **l, listint_t *r)
{
	int p;

	if (r == NULL)
		return (1);

	p = check_palindrome(l, r->next);

	if (p == 0)
		return (0);

	p = (r->n == (*l)->n);
	*l = (*l)->next;
	return (p);
}
/**
 * is_palindrome - checks if SLL is a palindrome
 * @head: double pointer to the head of SLL
 * Return: recursive
 */

int is_palindrome(listint_t **head)
{
	int counter = 0;
	listint_t *h = *head;
    while (h != NULL)
	{
		counter++;
		h = h->next;
	}
	if (counter == 0 || counter == 1)
		return (1);
	return (check_palindrome(head, *head));
}

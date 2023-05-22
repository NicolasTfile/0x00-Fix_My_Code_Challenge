#include "lists.h"
#include <stdlib.h>

/**
 * delete_dnodeint_at_index - Delete a node at a specific index from a list
 *
 * @head: A pointer to the first element of a list
 * @index: The index of the node to delete
 *
 * Return: 1 on success, -1 on failure
 */
int delete_dnodeint_at_index(dlistint_t **head, unsigned int index)
{
	dlistint_t *saved_head;
	dlistint_t *tmp;
	unsigned int p;

	if (*head == NULL)
	{
		return (-1);
	}

	saved_head = *head;

	if (index == 0)
	{
		*head = saved_head->next;
		if (*head != NULL)
			(*head)->prev = NULL;
		free(saved_head);
		return (1);
	}

	p = 0;
	while (saved_head != NULL && p < index - 1)
	{
		saved_head = saved_head->next;
		p++;
	}

	if (saved_head == NULL || saved_head->next == NULL)
	{
		return (-1);
	}

	tmp = saved_head->next;
	saved_head->next = tmp->next;

	if (tmp->next != NULL)
		tmp->next->prev = saved_head;

	free(tmp);
	return (1);
}

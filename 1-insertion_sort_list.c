#include "sort.h"

/**
  * insertion_sort_list - function that sorts a doubly linked list
  * using insertion sort algorithm
  * @list: the doubly linked list
  *
  * Return: Void
  */
void insertion_sort_list(listint_t **list)
{
	listint_t *curr, *previous, *tmp;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;
	curr = (*list)->next;

	while (curr != NULL)
	{
		tmp = curr;
		previous = curr->prev;

		while (previous != NULL && previous->n > tmp->n)
		{
			if (tmp->next != NULL)
				tmp->next->prev = previous;

			previous->next = tmp->next;
			tmp->prev = previous->prev;

			if (previous->prev != NULL)
				previous->prev->next = tmp;
			else
				*list = tmp;

			tmp->next = previous;
			previous->prev = tmp;

			print_list(*list);
			previous = tmp->prev;
		}

		curr = curr->next;
	}
}

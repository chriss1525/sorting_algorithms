#include "sort.h"

/**
 * cocktail_sort_list - sorts a doubly linked list of integers in ascending
 * order using the Cocktail shaker sort algorithm
 *
 * @list: doubly linked list to be sorted
 */
void cocktail_sort_list(listint_t **list)
{
	int swapped = 1;
	listint_t *start = *list;
	listint_t *end = NULL;
	listint_t *p = NULL;

	if (!list || !*list)
		return;

	while (swapped)
	{
		swapped = 0;
		p = start;

		while (p->next != end)
		{
			if (p->n > p->next->n)
			{
				/* Swap the nodes */
				if (p->prev)
					p->prev->next = p->next;
				else
					*list = p->next;
				p->next->prev = p->prev;
				p->prev = p->next;
				p->next = p->next->next;
				p->prev->next = p;
				if (p->next)
					p->next->prev = p;
				/* Print the list after each swap */
				print_list(*list);
				swapped = 1;
			}
			else
			{
				p = p->next;
			}
		}
		end = p;

		if (!swapped)
			break;

		swapped = 0;
		p = end;

		while (p->prev != start)
		{
			if (p->n < p->prev->n)
			{
				/* Swap the nodes */
				if (p->next)
					p->next->prev = p->prev;
				else
					end = p->prev;
				p->prev->next = p->next;
				p->next = p->prev;
				p->prev = p->prev->prev;
				p->next->prev = p;
				if (p->prev)
					p->prev->next = p;
				/* Print the list after each swap */
				print_list(*list);
				swapped = 1;
			}
			else
			{
				p = p->prev;
			}
		}
		start = p;
	}
}

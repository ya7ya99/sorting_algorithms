#include "sort.h"

/**
 * swap_node - Swaps two elements in a doubly linked list.
 * @list: Pointer to the head of the linked list.
 * @a: Pointer to the first element to be swapped.
 * @b: Pointer to the second element to be swapped.
 * @is_ahead: Indicates if 'a' is ahead of 'b' in the list.
 *
 * Description: This function swaps two elements in a doubly linked list.
 */
void swap_node(listint_t **list, listint_t **a, listint_t **b, int is_ahead)
{
	listint_t *tmp;

	if (is_ahead)
	{
		tmp = (*b)->next;
		if ((*b)->prev != NULL)
			(*b)->prev->next = tmp;
		else
			*list = tmp;
		tmp->prev = (*b)->prev;
		(*b)->next = tmp->next;
		if (tmp->next != NULL)
			tmp->next->prev = *b;
		else
			*a = *b;
		(*b)->prev = tmp;
		tmp->next = *b;
	}
	else
	{
		tmp = (*b)->prev;
		if ((*b)->next != NULL)
			(*b)->next->prev = tmp;
		else
			*a = tmp;
		tmp->next = (*b)->next;
		(*b)->prev = tmp->prev;
		if (tmp->prev != NULL)
			tmp->prev->next = *b;
		else
			*list = *b;
		(*b)->next = tmp;
		tmp->prev = *b;
	}
	*b = tmp;
}

/**
 * cocktail_sort_list - Sorts a doubly linked list in ascending order
 * using the Cocktail shaker sort algorithm.
 * @list: Pointer to the head of the linked list
 */
void cocktail_sort_list(listint_t **list)
{
	bool swapped = false;
	listint_t *current, *tail;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;
	for (tail = *list; tail->next != NULL;)
		tail = tail->next;
	do {
		swapped = true;
		for (current = *list; current != tail; current = current->next)
		{
			if (current->n > current->next->n)
			{
				swap_node(list, &tail, &current, 1);
				swapped = false;
				print_list((const listint_t *)*list);
			}
		}
		for (current = current->prev; current != *list;
				current = current->prev)
		{
			if (current->n < current->prev->n)
			{
				swap_node(list, &tail, &current, 0);
				print_list((const listint_t *)*list);
				swapped = false;
			}
		}
	} while (swapped == false);
}

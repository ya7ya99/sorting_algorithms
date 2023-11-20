#include "sort.h"

/**
 * swap - Swaps two nodes in a doubly linked list
 * @a: First node to swap
 * @b: Second node to swap
 */
void swap(listint_t *a, listint_t *b)
{
    if (a->prev)
        a->prev->next = b;
    if (b->next)
        b->next->prev = a;

    a->next = b->next;
    b->prev = a->prev;
    b->next = a;
    a->prev = b;
}

/**
 * cocktail_sort_list - Sorts a doubly linked list in ascending order
 * using the Cocktail shaker sort algorithm.
 * @list: Pointer to the head of the linked list
 */
void cocktail_sort_list(listint_t **list)
{
    int swapped;
    listint_t *current;

    if (list == NULL || *list == NULL || (*list)->next == NULL)
        return;

    do {
        swapped = 0;

        for (current = *list; current->next != NULL; current = current->next)
        {
            if (current->n > current->next->n)
            {
                swap(current, current->next);
                swapped = 1;
                print_list(*list);
            }
        }

        if (!swapped)
            break;

        swapped = 0;

        for (current = current->prev; current != NULL; current = current->prev)
        {
            if (current->n < current->prev->n)
            {
                swap(current->prev, current);
                swapped = 1;
                print_list(*list);
            }
        }
    } while (swapped);
}

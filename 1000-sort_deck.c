#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "deck.h"

/**
 * get_value - get a card value
 * @card: pointer to a card_t node
 * Return: the value of the card.
 */
int get_value(const card_t *card)
{
	value_mapping value_mappings[] = {
			{"Ace", 0},
			{"1", 1},
			{"2", 2},
			{"3", 3},
			{"4", 4},
			{"5", 5},
			{"6", 6},
			{"7", 7},
			{"8", 8},
			{"9", 9},
			{"10", 10},
			{"Jack", 11},
			{"Queen", 12},
			{"King", 13},
	};

	size_t i;

	for (i = 0; i < sizeof(value_mappings) / sizeof(value_mappings[0]); i++)
	{
		if (strcmp(card->value, value_mappings[i].value) == 0)
		{
			return (value_mappings[i].numeric_value);
		}
	}

	return (13);
}

/**
 * compare_cards - This function is used as a comparator
 * for the qsort function. It compares two cards to
 * determine their order in the sorted array.
 * @a: pointer to the first card.
 * @b: pointer to the second card.
 * Return:  integer less than, equal to,
 * or greater than zero if the first card
 * is considered to be respectively less than,
 * equal to, or greater than the second card.
 */
int compare_cards(const void *a, const void *b)
{
	const card_t *card_a = (*(const deck_node_t **)a)->card;
	const card_t *card_b = (*(const deck_node_t **)b)->card;
	int kind_diff, value_diff;

	kind_diff = (card_a->kind - card_b->kind);

	if (kind_diff != 0)
	{
		return (kind_diff);
	}
	else
	{
		value_diff = (get_value(card_a) - get_value(card_b));
		return (value_diff);
	}
}

/**
 * sort_deck - This function sorts a doubly-linked
 * list of cards (deck) using the qsort algorithm.
 * @deck: pointer to the head of the doubly-linked list.
 * Return: Nothing.
 */
void sort_deck(deck_node_t **deck)
{
	size_t size = 0, i;
	deck_node_t **deck_array, *current;

	if (deck == NULL || *deck == NULL || (*deck)->next == NULL)
		return;

	current = *deck;
	while (current != NULL)
	{
		size++;
		current = current->next;
	}
	deck_array = malloc(size * sizeof(deck_node_t *));
	if (deck_array == NULL)
		return;

	current = *deck;
	for (i = 0; i < size; ++i)
	{
		deck_array[i] = current;
		current = current->next;
	}

	qsort(deck_array, size, sizeof(deck_node_t *), compare_cards);

	for (i = 0; i < size - 1; i++)
	{
		deck_array[i]->next = deck_array[i + 1];
		deck_array[i + 1]->prev = deck_array[i];
	}

	*deck = deck_array[0];
	(*deck)->prev = NULL;
	deck_array[size - 1]->next = NULL;
	free(deck_array);
}

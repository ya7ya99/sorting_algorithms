#ifndef DECK_H
#define DECK_H
/**
 * enum kind_e - discribes cards !!
 * @SPADE: spade.
 * @HEART: heart.
 * @CLUB: club.
 * @DIAMOND: diamond.
 */
typedef enum kind_e
{
	SPADE = 0,
	HEART,
	CLUB,
	DIAMOND
} kind_t;

/**
 * struct card_s - Playing card
 *
 * @value: Value of the card
 * From "Ace" to "King"
 * @kind: Kind of the card
 */
typedef struct card_s
{
	const char *value;
	const kind_t kind;
} card_t;

/**
 * struct deck_node_s - Deck of card
 *
 * @card: Pointer to the card of the node
 * @prev: Pointer to the previous node of the list
 * @next: Pointer to the next node of the list
 */
typedef struct deck_node_s
{
	const card_t *card;
	struct deck_node_s *prev;
	struct deck_node_s *next;
} deck_node_t;

/**
 * struct value_mapping_s - A map of the char and int value of a card
 *
 * @value: Pointer to the value of a card
 * @numeric_value: The integer representation of @value
 */
typedef struct value_mapping_s
{
	const char *value;
	int numeric_value;
} value_mapping;

void sort_deck(deck_node_t **deck);
int compare_cards(const void *a, const void *b);
int get_value(const card_t *card);

#endif

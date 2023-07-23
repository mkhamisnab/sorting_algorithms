#ifndef DECK_H
#define DECK_H

/**
 * enum kind_e - Enumerates the kinds of playing cards.
 * @SPADE: Represents the spade kind.
 * @HEART: Represents the heart kind.
 * @CLUB: Represents the club kind.
 * @DIAMOND: Represents the diamond kind.
 */
typedef enum kind_e
{
	SPADE = 0,
	HEART,
	CLUB,
	DIAMOND
} kind_t;

/**
 * struct card_s - Defines a playing card.
 *
 * @value: The value of the card, ranging from "Ace" to "King".
 * @kind: The kind of the card, which can be SPADE, HEART, CLUB, or DIAMOND.
 */
typedef struct card_s
{
	const char *value;
	const kind_t kind;
} card_t;

/**
 * struct deck_node_s - Defines a node in a deck of cards.
 *
 * @card: Pointer to the playing card of the node.
 * @prev: Pointer to the previous node in the deck.
 * @next: Pointer to the next node in the deck.
 */
typedef struct deck_node_s
{
	const card_t *card;
	struct deck_node_s *prev;
	struct deck_node_s *next;
} deck_node_t;

/**
 * sort_deck - Sorts a deck of cards in ascending order based on their value
 *             and kind (spade, heart, club, diamond).
 *
 * @deck: Pointer to the head of the deck.
 */
void sort_deck(deck_node_t **deck);

#endif

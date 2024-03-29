#include <stdlib.h>
#include <stdio.h>
#include "deck.h"
 
void print_deck(const deck_node_t *deck);
 
/**
 * free_deck - frees a linked list deck of cards
 * @deck: deck to be freed
 *
 * Return: void
 */
void free_deck(deck_node_t *deck)
{
 deck_node_t *next;
 
 while (deck)
 {
 next = deck->next;
 free(deck);
 deck = next;
 }
}
 
/**
 * init_deck - initialize the linked list deck of cards
 * @cards: array of cards to be turned into a linked list
 *
 * Return: the new deck
 */
deck_node_t *init_deck(const card_t cards[52])
{
 deck_node_t *deck;
 deck_node_t *node;
 size_t i;
 
 i = 52;
 deck = NULL;
 while (i--)
 {
 node = malloc(sizeof(*node));
 if (!node)
 return (NULL);
 node->card = &cards[i];
 node->next = deck;
 node->prev = NULL;
 if (deck)
 deck->prev = node;
 deck = node;
 }
 return (deck);
}
 
/**
 * main - test the sort_deck fucntion
 *
 * Return: always 0
 */
int main(void)
{
 card_t cards[52] = {
 {"Jack", CLUB}, {"4", HEART}, {"3", HEART}, {"3", DIAMOND},
 {"Queen", HEART}, {"5", HEART}, {"5", SPADE}, {"10", HEART},
 {"6", HEART}, {"5", DIAMOND}, {"6", SPADE}, {"9", HEART},
 {"7", DIAMOND}, {"Jack", SPADE}, {"Ace", DIAMOND}, {"9", CLUB},
 {"Jack", DIAMOND}, {"7", SPADE}, {"King", DIAMOND},
 {"10", CLUB}, {"King", SPADE}, {"8", CLUB}, {"9", SPADE},
 {"6", CLUB}, {"Ace", CLUB}, {"3", SPADE}, {"8", SPADE},
 {"9", DIAMOND}, {"2", HEART}, {"4", DIAMOND}, {"6", DIAMOND},
 {"3", CLUB}, {"Queen", CLUB}, {"10", SPADE}, {"8", DIAMOND},
 {"8", HEART}, {"Ace", SPADE}, {"Jack", HEART}, {"2", CLUB},
 {"4", SPADE}, {"2", SPADE}, {"2", DIAMOND}, {"King", CLUB},
 {"Queen", SPADE}, {"Queen", DIAMOND}, {"7", CLUB}, {"7", HEART},
 {"5", CLUB}, {"10", DIAMOND}, {"4", CLUB}, {"King", HEART},
 {"Ace", HEART}
 };
 deck_node_t *deck;
 
 deck = init_deck(cards);
 print_deck(deck);
 printf("\n");
 sort_deck(&deck);
 printf("\n");
 print_deck(deck);
 free_deck(deck);
 return (0);
}

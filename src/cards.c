#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include "cards.h"

#define MAX_HAND_SIZE 7
#define DECK_SIZE 52
#define CARDS_PER_SUIT 13

void CreateCards(Deck* deck, int suit) {
  Card* card = NULL;
  card = (Card*) malloc(sizeof(Card) * 1);

  int i;
  
  for (i = 0; i < CARDS_PER_SUIT; i++) {
    card->suit = suit; 
    card->value = i;

    switch (suit) { 
      case 1: // CLUBS
        deck->clubs[i] = *card; 
        break;
      case 2: // SPADES 
        deck->spades[i] = *card; 
        break;
      case 3: // HEARTS 
        deck->hearts[i] = *card; 
        break;
      case 4: // DIAMONDS 
        deck->diamonds[i] = *card; 
        break;
    }
  }

  free(card);
  card = NULL;
}


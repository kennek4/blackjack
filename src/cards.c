#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include "cards.h"

#define MAX_HAND_SIZE 7
#define DECK_SIZE 52
#define CARDS_PER_SUIT 13

enum Suit{
  CLUBS = 1,
  SPADES,
  HEARTS,
  DIAMONDS,
};

void CreateDealerDeck(Card* deck) {

  Card* card = NULL;
  card = (Card*) malloc(sizeof(Card) * 1);

  int suit, value;

  // Create all cards per suit
  for (suit = CLUBS; suit <= DIAMONDS; suit++) {

    card->suit = suit;

    // Add special cards (Ace and Faces)
    for (value = 0; value < 4; value ++) {
      if (value == 0) {
        card->value = 0; // Ace
      } else {
        card->value = 10;
      }

      deck[suit * value] = *card;
    }
    
    // Add numbered cards 
    for (value = 4; value < CARDS_PER_SUIT; value++) {
      printf("%d\n", value);  
    }
  } 

  free(card);
  card = NULL;
}

void AddToHand(Card hand[], HandSize* handSize) {

  Card newCard;
  newCard.value = 21;
  newCard.suit = CLUBS; 

  if ((*handSize + 1) < MAX_HAND_SIZE) {

    printf("Hand Size before: %d\n", *handSize);
    hand[*handSize + 1] = newCard; 
    *handSize += 1;
    printf("Hand Size after: %d\n", *handSize);

    printf("Added new card to player hand\n");
  }

}

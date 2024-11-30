#include "cards.h"
#include <stddef.h>

#define MAX_HAND_SIZE 7

unsigned char CLUBS = 'C';
unsigned char DIAMONDS = 'D';
unsigned char HEARTS = 'H';
unsigned char SPADES = 'S';

Card g_playerHand[11];
HandSize g_playerCardCount = 0;
HandSize* ptrPlayerCardCount = &g_playerCardCount;

void AddToHand(Card hand[], HandSize* handSize) {

  Card newCard;
  newCard.value = 21;
  newCard.suit = CLUBS; 

  if ((*handSize + 1) < MAX_HAND_SIZE) {
    hand[*handSize + 1] = newCard; 
  }

}

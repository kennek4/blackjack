#ifndef CARDS_H 
#define CARDS_H

typedef struct {
  unsigned char value;
  char suit;
} Card;

typedef unsigned char HandSize;

void CreateDeck(Card* deck);
void AddToHand(Card hand[], HandSize* handSize);


#endif // CARDS_H

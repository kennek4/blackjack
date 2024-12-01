#ifndef CARDS_H 
#define CARDS_H

enum Suit{
  CLUBS = 1,
  SPADES,
  HEARTS,
  DIAMONDS,
};

typedef struct {
  unsigned char value;
  char suit;
} Card;

typedef struct {
  Card* clubs;
  Card* spades;
  Card* hearts;
  Card* diamonds;
} Deck;

typedef struct {
  Card* cards;
  unsigned char handValue; // The sum value of every card in cards
  unsigned char cardCount; // The amount of cards in cards
} Player;



void CreateCards(Deck* deck, int suit);

#endif // CARDS_H

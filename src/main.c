
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include "cards.h"

#define BLACK_JACK 21
#define MAX_PLAYER_HAND 9 // Drawing a 2 from each suit, Drawing a 3 from each suit, then drawing an Ace

Player* gPlayer = NULL;
Player* gDealer = NULL;
Deck* gGameDeck = NULL;

void loadGameVariables() {
  
  gPlayer = (Player*) malloc(sizeof(Player) * 1);
  gDealer= (Player*) malloc(sizeof(Player) * 1);

  gPlayer->cards = (Card*) malloc(sizeof(Card) * MAX_PLAYER_HAND);
  gDealer->cards = (Card*) malloc(sizeof(Card) * MAX_PLAYER_HAND);

  gGameDeck = (Deck*) malloc(sizeof(Deck) * 1);
  gGameDeck->clubs = (Card*) malloc(sizeof(Card) * 13);
  gGameDeck->spades = (Card*) malloc(sizeof(Card) * 13);
  gGameDeck->hearts = (Card*) malloc(sizeof(Card) * 13);
  gGameDeck->diamonds = (Card*) malloc(sizeof(Card) * 13);

  CreateCards(gGameDeck, CLUBS); 
  CreateCards(gGameDeck, SPADES); 
  CreateCards(gGameDeck, HEARTS); 
  CreateCards(gGameDeck, DIAMONDS); 
}

void freeGameVariables() {
  if (gPlayer->cards != NULL && gDealer->cards != NULL && gGameDeck != NULL) {
    // Free Inner mallocs
    free(gPlayer->cards);
    free(gDealer->cards);

    // Free player structs
    free(gPlayer);
    free(gDealer);

    // Free card deck
    free(gGameDeck->clubs);
    free(gGameDeck->spades);
    free(gGameDeck->hearts);
    free(gGameDeck->diamonds);
    free(gGameDeck);
  } else {
    printf("No variables to free from memory\n");
  }
}

int main(void)
{ 
  
  loadGameVariables();

  // Handle exit and interrupt behaviour
  atexit(freeGameVariables);
  signal(SIGINT, freeGameVariables);

  return EXIT_SUCCESS;
}

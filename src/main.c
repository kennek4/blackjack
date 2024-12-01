
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include "cards.h"

#define MAX_PLAYER_HAND 7

Card* gPlayerHand = NULL;
Card* gDealerHand = NULL;
Card* gGameDeck = NULL:
HandSize gPlayerCardCount = 0;

void loadGameVariables() {
  if (gPlayerHand == NULL) {
    gPlayerHand = (Card*) malloc(sizeof(Card) * MAX_PLAYER_HAND);
  } else {
    exit(EXIT_FAILURE); // gPlayerHand initialized with a value, UNEXPECTED BEHAVIOUR
  } 
}

void freeGameVariables() {
  if (gPlayerHand != NULL) {
    free(gPlayerHand); 
    gPlayerHand = NULL;
  }
}

int main(void)
{ 
  // Hanlde exit and interrupt behaviour
  atexit(freeGameVariables);
  signal(SIGINT, freeGameVariables);

  loadGameVariables();
  
  AddToHand(gPlayerHand, &gPlayerCardCount); 
  printf("Player Hand Count: %d\n", gPlayerCardCount); 

  return EXIT_SUCCESS;
}

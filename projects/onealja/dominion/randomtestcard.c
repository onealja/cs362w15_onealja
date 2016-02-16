#include "dominion.h"
#include "rngs.h"
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include "my_assert.h"

#define MAX_TESTS 1500

//This randomly tests great_hall

int main() {

	  int k[10] = {adventurer, gardens, embargo, village, minion, mine, cutpurse, 
	       great_hall, tribute, smithy};

	  int i, players, player, handCount, deckCount, actions, seed;
	  int fail = 0;
	  struct gameState state;


	  srand(time(NULL));

	  printf("\n***** Begin Random Card Test: great_hall *****\n");


	  for (i = 0; i < MAX_TESTS; i++) {

	     	 state.numActions = 1; //reset actions
		 state.playedCardCount = 0; //reset played cards

		 printf("\nTEST %d\n", i);

		 players = (rand() % 4) + 1;

		 printf("number of players: %d\n", players);
		 
		 player = (rand() % players) + 1;
		 
		 printf("player %d chosen\n", player);
		 

		 seed = rand();		//pick random seed
		
		 initializeGame(players, k, seed, &state);	//initialize Gamestate

		  state.deckCount[player] = (rand() % MAX_DECK) + 1; 
		  state.discardCount[player] = 0;
		  state.handCount[player] = 5;

		  state.whoseTurn = player;

		  //Copy state variables
		  handCount = state.handCount[player];
		  deckCount = state.deckCount[player];
		  actions = state.numActions;
		  
		  printf("test: %d\n", i);
		  printf("hand count: %d\n", handCount);
		  printf("deck count: %d\n", deckCount);
		  printf("action count: %d\n", actions);

		  cardEffect(great_hall, 1, 1, 1, &state, 0, 0);

		  fail += assert(state.handCount[player] == handCount); //check hand count hasn't changed
		  fail += assert(state.deckCount[player] == (deckCount - 1)); //make sure one card drawn
		  fail += assert(state.numActions == (actions + 1)); //make sure actions incremented
		  fail += assert(state.playedCardCount == 1); //make sure one card was played


		  printf("round end\n\n");
	  }

	  printf("Tests Complete\nFAILS: %d\n", fail);


	  return 0;
}

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
	       sea_hag, tribute, smithy};

	  int i, players, player, handCount, deckCount, seed;
	  int fail = 0; //fail count
	  struct gameState state;


	  srand(time(NULL));

	  printf("\n***** Begin Random Card Test: adventurer *****\n");


	  for (i = 0; i < MAX_TESTS; i++) {

		 state.playedCardCount = 0; //reset played card count

		 printf("\nTEST %d\n", i);

		 players = (rand() % 4) + 1;

		 printf("number of players: %d\n", players);
		 
		 player = (rand() % players) + 1;
		 
		 printf("player %d chosen\n", player);
		 

		 seed = rand();		//pick random seed
		
		 initializeGame(players, k, seed, &state);	//initialize Gamestate

		  state.deckCount[player] = (rand() % MAX_DECK) + 1; //initialize deck count to a random size within max deck size
		  state.discardCount[player] = 0; //reset discard count
		  state.handCount[player] = 5; //reset hand count

		  state.whoseTurn = player; //make sure it is currently picked players turn

		  //Copy state variables
		  handCount = state.handCount[player];
		  deckCount = state.deckCount[player];
		  
		  printf("hand count: %d\n", handCount);
		  printf("deck count: %d\n", deckCount);

		  cardEffect(adventurer, 1, 1, 1, &state, 0, 0); //run card

		  fail += assert(state.handCount[player] == 7); //make sure hand size is now two more
		  fail += assert(state.deckCount[player] == (deckCount - state.discardCount[player] - 2)); //make sure current deck count is correct
		  printf("dicarded cards: %d\n", state.discardCount[player]);
		  printf("new deck count: %d\n", state.deckCount[player]);


		  printf("round end\n\n");
	  }

	  printf("Tests Complete\nFAILS: %d\n", fail);


	  return 0;
}








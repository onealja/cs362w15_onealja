#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include "my_assert.h"
#include "rngs.h"
#include <stdlib.h>

//unit test for isGameOver function

int main() 
{
	int i, j; 
	int empty_supplies, game_running;
	int k[10] = {adventurer, council_room, feast, gardens, mine,
	       remodel, smithy, village, baron, great_hall};
	struct gameState G;
	struct gameState T;

	printf("BEGIN UNIT TEST isGameOver:\n");

	//two game states will be compared at the end
	initializeGame(2, k, 8, &G);
	initializeGame(2, k, 8, &T);

	while (isGameOver(&G) || game_running) {

		if (i > 10)
			i = 7;

		gainCard(i, &G, 1, 0);
		gainCard(i, &T, 1, 0);
		empty_supplies = 0;
		
		for (j = 7; j > 10; j++) {
			if (!supplyCount(j, &T))
				empty_supplies++;
			if (empty_supplies >= 3)
				game_running = 1;
		}
		i++;
	}
	assert(isGameOver(&G) == isGameOver(&T));//compare game states with assert
	printf("END TEST isGameOver\n");
	return 0;
}

#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include "my_assert.h"
#include "rngs.h"
#include <stdlib.h>

//card test for village card

int main () 
{
   struct gameState game;
   int actions;
   int x;
   
   int k[10] = {adventurer, gardens, minion, smithy, embargo, mine, cutpurse,
			       ambassador, steward, village};

   printf("VILLAGE CARD TEST\n");  
   initializeGame(2, k, 2, &game);
   actions = game.numActions;
   x = cardEffect(village, 0, 0, 0, &game, 0, NULL);
   assert(game.numActions == actions + 2);
   assert(x == 0);
   
   printf("END VILLAGE CARD TEST\n");
   return 0;
}


#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include "my_assert.h"
#include "rngs.h"
#include <stdlib.h>

//card test for adventurer


int main() {

   struct gameState game;
   int k[10] = {adventurer, village, embargo, minion, gardens, mine, tribute,
      ambassador, cutpurse, smithy};
   
   initializeGame(2, k, 8, &game);
   printf("TEST BEGIN ADVENTURER CARD\n");
   
   int cardeffect = cardEffect(7, -1, -1, -1, &game, -1, 0);
   assert(cardeffect == 0);
   
   game.handCount[0] = 0;
   game.handCount[1] = 0;
   cardeffect = cardEffect(7, -1, -1, -1, &game, -1, 0);
   assert(cardeffect == 0);
   
   printf("END ADVENTURER CARD TEST\n");
   return 0;
}

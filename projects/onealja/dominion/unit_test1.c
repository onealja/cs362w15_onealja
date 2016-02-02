#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include "my_assert.h"
#include "rngs.h"
#include <stdlib.h>

//unit test for function numHandCards()

int main(){
   int k[10] = {mine, council_room, baron, smithy, adventurer,
	       remodel, gardens, village, feast, great_hall};
   int h = 0;
   int m, i;
  
   struct gameState G;
   printf("Testing numHandCards function: \n");
   printf("i and handCount should equal each other.\n");
   m = initializeGame(2, k, 1, &G);
   
   for (i = 0; i < 10; i++)
   {
      printf("i: %d\n", i);
      G.handCount[0] = i;
      h = numHandCards(&G);
      printf ("handCount: %d\n", h);
      assert(i == h); 
   }
   printf("END UNIT TEST 1\n");
   return 0;
}

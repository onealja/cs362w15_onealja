#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include "my_assert.h"
#include "rngs.h"
#include <stdlib.h>

//unit test for function updateCoins()

int main()
{
   struct gameState G;
   int x;

   printf("unit test 4 updateCoins:\n");
	
   G.handCount[0] = 3;
   G.hand[0][0] = gold;
   G.hand[0][1] = copper;
   G.hand[0][2] = silver;
	
   x = updateCoins(0, &G, 3);
   assert(x == 0);
   assert(G.coins == 9);

   return 0;
}

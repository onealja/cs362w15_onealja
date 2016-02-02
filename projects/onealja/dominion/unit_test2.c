#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include "my_assert.h"
#include "rngs.h"
#include <stdlib.h>

//unit test for function whoseTurn()

int main() 
{
    struct gameState G; 
    int x, num_players;
    int k[10] = {adventurer, gardens, minion, village, embargo, mine, cutpurse, baron, tribute, smithy};

    for (num_players = 2 ; num_players < 5 ; ++num_players) 
    {
        x = initializeGame(num_players, k, 5, &G);
        assert (x == 0);
        x = whoseTurn(&G);
	printf("players: %d\n", num_players);
        assert (x == G.whoseTurn);
    }

    printf("END UNIT TEST 2\n");

return 0;
}

#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include "my_assert.h"
#include "rngs.h"
#include <stdlib.h>


int main() {
   struct gameState game;
   int i;
   int k[10] = {adventurer, council_room, feast, gardens, mine, remodel, smithy, village, baron, great_hall};

        printf("COUNCIL_ROOM CARD TEST BEGIN:\n");

        assert(initializeGame(2, k, 33, &game) == 0);

        for (i = 0; i < 2; i++) {

                game.whoseTurn = i;
                game.handCount[i] = 1;
                game.hand[i][0] = council_room;
                assert(cardEffect(council_room, 0, 0, 0, &game, 0, NULL) == 0);
                assert(game.handCount[i] == 4);
                assert(game.numBuys += 1);
        }

        printf("END COUNCIL_ROOM CARD TEST\n");

        return 0;
}

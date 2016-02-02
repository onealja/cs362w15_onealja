#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include "my_assert.h"
#include "rngs.h"
#include <stdlib.h>

//card test for smithy

int main(){

	struct gameState game;
	int k[10] = {embargo, great_hall, gardens, village, smithy, minion, adventurer, cutpurse, ambassador, mine};
	initializeGame(2, k, 8, &game);
	int player = game.whoseTurn;

	printf("BEGIN CARD TEST FOR SMITHY:\n");
	printf("cards: %d\n", game.handCount[player]);
	printf("actions: %d\n", game.numActions);
	printf("deck size: %d\n", game.deckCount[player]);
	printf("discarded: %d\n", game.discardCount[player]);



	game.handCount[player] = 0;
	game.hand[player][0] = k[0];

	int i;
	for(i = 0; i < 5; i++){
		if(i < 5)
			gainCard(1, &game, 1, player);

		else
			gainCard(i+1, &game, 1, game.whoseTurn);
	}

	drawCard(game.whoseTurn, &game);

	int h_count = game.handCount[player] + 2;
	int d_count = game.deckCount[player] - 3;
	int a_count = game.numActions;
	int dis_count = game.discardCount[player] + 1;

	cardEffect(smithy, 0, 1, 1, &game, 0, 0);

	printf("expected hand size: %d\n", h_count);
	assert(h_count == game.handCount[player]);
	printf("expected actions: %d\n", a_count);
	assert(a_count == game.numActions);
  	printf("expected deck: %d\n", d_count);
	assert(d_count == game.deckCount[player]);
  	printf("expected discard: %d\n", dis_count);
	assert(dis_count == game.discardCount[player]);

  	//bug in smithy, number of cards in deck is not correct



	return 0;
}

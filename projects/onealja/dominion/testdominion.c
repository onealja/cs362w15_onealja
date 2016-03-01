#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

const char* cardName(int cardVal){

    switch(cardVal){
        case curse:
            return "curse";
        case estate:
            return "estate";
        case duchy:
            return "duchy";
        case province:
            return "province";
        case copper:
            return "copper";
        case silver:
            return "silver";
        case gold:
            return "gold";
        case adventurer:
            return "adventurer";
        case council_room:
            return "council room";
        case feast:
            return "feast";
        case gardens:
            return "gardens";
        case mine:
            return "mine";
        case remodel:
            return "remodel";
        case smithy:
            return "smithy";
        case village:
            return "village";
        case baron:
            return "baron";
        case great_hall:
            return "great hall";
        case minion:
            return "minion";
        case steward:
            return "steward";
        case tribute:
            return "tribute";
        case ambassador:
            return "ambassador";
        case cutpurse:
            return "cutpurse";
        case embargo:
            return "embargo";
        case outpost:
            return "outpost";
        case salvager:
            return "salvager";
        case sea_hag:
            return "sea hag";
        case treasure_map:
            return "treasure map";
    }

    return "ERROR";
}

int main(int argc, char *argv[]){

	char *newline = "\n";
	srand(time(NULL));
	int seed;
	int player;

	int advenPos;
	int villagePos;
	int minionPos;
	int minePos;
	int tribPos;
	int embargoPos;
	int cutPos;
	int gardenPos;
	int smithyPos;
	int seaPos;
	int money;
	
	int i,j;
	int choice;
	int players[5] = {-1,-1,-1,-1,-1};	
	int round = 0;

	struct gameState state;
	
	int k[10] = {adventurer, gardens, embargo, village, minion, mine, cutpurse, sea_hag, tribute, smithy};
	
	if (argc <= 1){
		seed = rand();
		player = (rand() % 4) + 1;
		
	}
	else if (argc == 2) {
		seed = rand();
		player = atoi(argv[1]);
	}
	else if (argc >= 3) {
		seed = atoi(argv[2]);
		player = atoi(argv[1]);
	}
	
	printf ("Begin Dominion Test: %d players\n", player);

	initializeGame(player, k, seed, &state);
	
	while (isGameOver(&state) == 0){
		
		printf("\n%d players turn\n", whoseTurn(&state)+1);
		choice = rand() % 101;
			money = 0, smithyPos = -1, advenPos = -1, gardenPos = -1, embargoPos = -1, villagePos = -1, minionPos = -1, minePos = -1, cutPos = -1, seaPos = -1, tribPos = -1;
			while(numHandCards(&state) < 5){
				drawCard(whoseTurn(&state) , &state);
			}
			for (i = 0; i < numHandCards(&state); i++){
				printf("%s\t", cardName(handCard(i, &state)));
			}
			puts(newline);
		for (j = 0; j < numHandCards(&state); j++) { 
			if (handCard(j, &state) == copper){
    			money++;
    			playCard(j, -1, -1, -1, &state);
    		}
      		else if (handCard(j, &state) == silver){
    			money += 2;
    			playCard(j, -1, -1, -1, &state);
    		}
      		else if (handCard(j, &state) == gold){
    			money += 3;
    			playCard(j, -1, -1, -1, &state);
    		}
    		else if (handCard(j, &state) == smithy){
				smithyPos = j;
			}
			else if (handCard(j, &state) == adventurer){
				advenPos = j;
			}
			else if (handCard(j, &state) == gardens){
				gardenPos = j;
			}
			else if (handCard(j, &state) == embargo){
				embargoPos = j;
			}
			else if (handCard(j, &state) == village){
				villagePos = j;
			}
			else if (handCard(j, &state) == minion){
				minionPos = j;
			}
			else if (handCard(j, &state) == mine){
				minePos = j;
			}
			else if (handCard(j, &state) == cutpurse){
				cutPos = j;
			}
			else if (handCard(j, &state) == sea_hag){
				seaPos = j;
			}
			else if (handCard(j, &state) == tribute){
				tribPos = j;
			}
		}

		
		if (advenPos != -1){
			printf("Played adventurer Card\n");
			playCard(advenPos, -1, -1, -1, &state);
		}
		if (smithyPos != -1){
			printf("Played smithy Card\n");
			playCard(smithyPos, -1, -1, -1, &state);
		}
		if (minePos != -1){
			printf("Played mine Card\n");
			playCard(minePos, -1,-1,-1, &state);
		}
		if (minionPos != -1) {
			printf("Played minion Card\n");
			playCard(minionPos,-1,-1,-1,&state);
		}
		if (tribPos != -1) {
			printf("Played tribute Card\n");
		}
		if (cutPos != -1) {
			printf("Played cutpurse\n");
			playCard(cutPos,-1,-1,-1,&state);
		}
		if (gardenPos != -1) {
			printf("Played gardens\n");
			playCard(gardenPos,-1,-1,-1,&state);
		}
		if (seaPos != -1) {
			printf("Played sea hag\n");
		}
		if (villagePos != -1){
			printf("Played village Card\n");
			playCard(villagePos,-1,-1,-1,&state);
		}
		if (embargoPos != -1){
			printf("Played embargo Card\n");
			playCard(embargoPos, -1,-1,-1,&state);
		}

		printf("Current money: %d\n", money);
		if (money >= 8) {
        	printf("bought province\n"); 
        	buyCard(province, &state);
		}
		else if (money >= 6) {
			if (choice <= 50){
				printf("bought me some adventurer\n");
				buyCard(adventurer, &state);
			}
			else {
        		printf("bought gold\n"); 
        		buyCard(gold, &state);
        	}
        }
        else if (money >= 5){
        	if (choice <= 33) {
        		printf("Bought mine\n");
        		buyCard(mine, &state);
        	}
        	else if (choice > 33 && choice <=66){
        		printf("Bought minion\n");
        		buyCard(minion, &state);
        	}
        	else if (choice > 66){
        		printf("Bought tribute\n");
        		buyCard(tribute, &state);
        	}
        }
		else if (money >= 4) {
			if (choice <= 25){
				printf("bought gardens\n"); 
        		buyCard(gardens, &state);
			}
			else if (choice > 25 && choice <= 50) {
        		printf("bought smithy\n"); 
        		buyCard(smithy, &state);
      		}
      		else if (choice > 50 && choice <= 75) {
      			printf("bought cutpurse\n"); 
        		buyCard(cutpurse, &state);
      		}
      		else if (choice > 75){
      			printf("bought sea hag\n"); 
        		buyCard(sea_hag, &state);
      		}
      	}
		else if (money >= 3) {
			if (choice <= 50){
        		printf("bought silver\n"); 
        		buyCard(silver, &state);
        	}
        	else {
        		printf("bought village\n");
        		buyCard(village, &state);
        	}
      	}
      	else if (money >= 2){
      		if(choice <=50){
      			printf("bought estate\n");
      			buyCard(estate, &state);
      		}
      		else if(choice >50){
      			printf("bought embargo\n");
      			buyCard(embargo, &state);
      		}
      	}
		endTurn(&state);
    	round++;
    	if (round >= 10000){
    	}
	}
	
	printf ("Finished game with %d rounds.\n", round);
	getWinners(players, &state);
	for (i = 0; i < player; i++){
	}
	puts(newline);
	for (i = 0; i < player; i++){
		if (players[i] != 0){
		}
	}

	return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "card_functions.h"
#include "player_functions.h"
#include "progress_functions.h"
#include "result_functions.h"
#include "variable.h"


int main(int argc, char *argv[]) {

	cardIndex = 0;
	gameEnd = 0;
	stay = 0;
	
	int roundIndex = 0;
	int max_user;
	int i, j, k;
	int a[N_CARD];
	
	srand((unsigned)time(NULL));
	
	n_user = configUser();										

	//Game initialization --------
	//1. players' dollar
	for(i = 0; i <= n_user; i++) {
		dollar[i] = N_DOLLAR;
	}
	
	//2. card tray	
	mixCardTray();
	
	//Game start --------
	do {
		roundIndex++;
		
		printf("\n-----------------------------------------\n");
		printf("--------- ROUND %d (cardIndex: %d) ---------\n", roundIndex, cardIndex);
		printf("-----------------------------------------\n\n");
		
		offerCards(); //1. give cards to all the players
		
		printf("------------- BETTING STEP -------------\n");
		bet[0] = betDollar();
		
		for(i = 1; i < n_user; i++) {
			bet[i] = (rand() % N_MAX_BET )+ 1;
			printf("  -> player%d bets $%d (out of $50)\n", i, bet[i]);
		}
		bet[n_user] = rand() % N_MAX_BET + 1;	// Amount of betting on the server

		printf("----------------------------------------\n\n");
		
		if(cardIndex > 52) {
			continue;
		}
		
		printf("------------- CARD OFFERING -------------\n");
		printCardInitialStatus();
	
		printf("\n-------------- GAME start --------------\n");
		printf(">>> my turn! ----------\n");
	
		//each player's turn
		while(cardSum[0] <= 21 && stay == 0) //do until the player dies or player says stop
		{
			printUserCardStatus(0, Index[0]);	//print current card status
			calcStepResult(0);	//check the card status :::
			getAction();		//GO? STOP? :::
			//check if the turn ends or not
			if(cardSum[0] > 21) {
				printf("OTL\n   ::: DEAD (sum: %d) --> -$%d ($%d)\n\n", cardSum[0], bet[0], dollar[0]);
			}
		}
		
		// Receive additional cards if the sum of the players or server cards is less than 17
		for(i = 1; i <= n_user; i++) {
			
			if(i != n_user) {
				printf(">>> player %d turn! ----------\n", i);
			}
			else if(i == n_user) {
				printf(">>> server turn! ----------\n");	// server
			}
			
			while(cardSum[i] < 17) {				
				
				printUserCardStatus(i, Index[i]);
				calcStepResult(i);
				printf("Card Sum is %d -> GO!\n", cardSum[i]);
				
				cardhold[i][Index[i]] = pullCard();
				cardSum[i] += getCardNum(cardhold[i][Index[i]]);
				Index[i]++;
			}
			
			printUserCardStatus(i, Index[i]);
			calcStepResult(i);
			
			if(getCardNum(cardhold[i][0]) + getCardNum(cardhold[i][1]) == 21) {	
				printf("(@>_<@)/\n   ::: Black Jack! Congratulation, You Win!! --> +$%d ($%d)\n\n", 2*bet[i], dollar[i]);
			}
			
			else if(cardSum[i] <= 21 && getCardNum(cardhold[i][0]) + getCardNum(cardhold[i][1]) != 21) {
				printf("Card Sum is %d -> STAY!\n\n", cardSum[i]);
			}
		
			else if(cardSum[i] > 21) {
				printf("OTL\n   ::: DEAD (sum: %d) --> -$%d ($%d)\n\n", cardSum[i], bet[i], dollar[i]);
			}
			
			else {
				printf("***ERROR***\n");
			}
		}
		
		printf("[[[[[ server result is ... %d ]]]]]", cardSum[n_user]);
			
		stay--;
		printf("\n");
		
		//cards that currently the players hold
		//result
		checkResult(n_user);
		
		if(cardIndex > 52) {
			gameEnd++;
		}
		
	} while (gameEnd == 0 && cardIndex <= 52 && dollar[0] != 0);
	
	gameEnd++;		// A virtually unnecessary part
	checkWinner();

	return 0;
}

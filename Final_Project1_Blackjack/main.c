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

/*	int t;
		
	mixCardTray();
	
	for(t = 0; t < 52; t++) {
		CardTray[t] = t + 1;
		printf("%d", getCardNum(CardTray[t]));
		printCard(CardTray[t]);
	}
	printf("\n\n");
	*/
	
//	printf("%d\n", CardTray[3][4]);
	
//	int ran_num;
//	int cardnum;
	
//	for(ran_num = 1; ran_num <= 52; ran_num++) {

//		printf("%d\n", printCard(&cardnum, &ran_num));
//	}

	cardIndex = 0;
	gameEnd = 0;
	stay = 0;
	
	int roundIndex = 0;
	int max_user;
	int i, j, k;
	int a[N_CARD];
	
	srand((unsigned)time(NULL));
	
/*	printf("--- server		: X ");
	printf("%d\n", mixCardTray());
	printf("  -> you		: ");
	printf("%d %d\n", mixCardTray(), mixCardTray());
	
	for(j = 1; j < n_user - 1; j++) {
	printf("  -> player %d		: ", j);
	printf("%d %d\n", mixCardTray(), mixCardTray());
	}
	*/
/*	printf("--- server		: X ");
	printf("%d\n", mixCardTray());
//	printf("  -> you		: %d %d\n", mixCardTray(), mixCardTray());
//	printf("  -> player 1	: %d %d\n", mixCardTray(), mixCardTray());
//	printf("  -> player 2	: %d %d\n\n", mixCardTray(), mixCardTray());
	printf("  -> you		: ");
	printf("%d %d\n", mixCardTray(), mixCardTray());
	printf("  -> you		: ");
	printf("%d\n", mixCardTray());
	*/

/*	printCard(&a[N_CARD]);
	printf("%d", a[0]);

	printCard();
	
	char A[52] = "HRT";
	char B = '2';

	strcat(A, B);
	
	printf("%s\n", A);
	printf("%s\n", B);
	
	char HRT = getchar();
	printf("%c\n", HRT);
	*/
	
	//set the number of players
	
	n_user = configUser();										

	//Game initialization --------
	//1. players' dollar
	for(i = 0; i <= n_user; i++) {
		dollar[i] = N_DOLLAR;
	}
	

	//2. card tray	
	mixCardTray();
	
/*	int t;
	
	for(t = 0; t < n_user; t++) {
		printf("%d", getCardNum(cardhold[t][0]));
		printCard(cardhold[t][0]);
		printf("\n\n");
	}
	*/
	
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
	
/*	printf("--- server		: %d %d\n", mixCardTray(), mixCardTray());
	printf("  -> you		: %d %d\n", mixCardTray(), mixCardTray());
	printf("  -> player 1	: %d %d\n", mixCardTray(), mixCardTray());
	printf("  -> player 2	: %d %d\n\n", mixCardTray(), mixCardTray());
	*/
	
//	int (*ptr)(void);
//	ptr = offerCards;
	
		printf("\n-------------- GAME start --------------\n");
	
		printf(">>> my turn! ----------\n");
	
		//each player's turn
//		for(i = 0; i < n_user; i++) //each player
//		{
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
//		}
		
		// Receive additional cards if the sum of the players or server cards is less than 17
//		switch(i) {
//			case 0:
//				break;
//			default:
		for(i = 1; i <= n_user; i++) {
			
			if(i != n_user) {
				printf(">>> player %d turn! ----------\n", i);
			}
			else if(i == n_user) {
				printf(">>> server turn! ----------\n");	// server
			}
			
/*			switch(i) {
				case 'n_user':
					printf(">>> server turn! ----------\n");	// server
					break;
				default:
					printf(">>> player %d turn! ----------\n", i);
					break;
			}
			*/
			
			while(cardSum[i] < 17) {
//				&& (cardSum[0] > 21 || stay == 1				
				
				printUserCardStatus(i, Index[i]);
				calcStepResult(i);
				printf("Card Sum is %d -> GO!\n", cardSum[i]);
				
				cardhold[i][Index[i]] = pullCard();
				cardSum[i] += getCardNum(cardhold[i][Index[i]]);
				Index[i]++;
			}
			
//			if(cardSum[i] >= 17) {
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
//			}
			
//			break;
		}
		
		printf("[[[[[ server result is ... %d ]]]]]", cardSum[n_user]);
		
/*		printf(">>> server turn! ----------\n");	// server
		while(cardSum[n_user] < 17 && (cardSum[n_user] > 21 || stay == 1)) {
			
			printUserCardStatus(n_user, Index[n_user]);
			calcStepResult(n_user);
			printf("GO!\n");
			
			cardhold[n_user][Index[n_user]] = pullCard();
			cardSum[n_user] += cardhold[n_user][Index[n_user]];
			Index[n_user]++;
		}
		
		if(cardSum[n_user] > 17) {
			printUserCardStatus(n_user, Index[n_user]);
			calcStepResult(n_user);
			
			if(getCardNum(cardhold[n_user][0]) + getCardNum(cardhold[n_user][1]) == 21) {	
				printf("(@>_<@)/\n   ::: Black Jack! Congratulation, You Win!! --> +$%d ($%d)\n", 2*bet[n_user], dollar[n_user]);
			}
			
			else if(cardSum[n_user] <= 21 && getCardNum(cardhold[n_user][0]) + getCardNum(cardhold[n_user][1]) != 21) {
				printf("STAY!\n");
			}
		
			else if(cardSum[n_user] > 21) {
				printf("OTL\n   ::: DEAD (sum: %d) --> -$%d ($%d)\n", cardSum[n_user], bet[n_user], dollar[n_user]);
			}
			
			else {
				printf("***ERROR***\n");
			}
		}
		printf("[[[[[ server result is ... %d ]]]]]", cardSum[n_user]);
		*/
			
//		calcStepResult();
			
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

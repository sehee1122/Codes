#include "progress_functions.h"

#define N_CARDSET			1
#define N_CARD				52
#define N_DOLLAR			50

#define N_MAX_CARDNUM		13
#define N_MAX_USER			5
#define N_MAX_CARDHOLD		10
#define N_MAX_GO			17
#define N_MAX_BET			5

#define N_MIN_ENDCARD		30

//card tray object
extern int CardTray[N_CARDSET*N_CARD];
extern int cardIndex;
extern int Index[N_MAX_USER];
extern int Ace[N_MAX_USER];			


//player info
extern int dollar[N_MAX_USER];						//dollars that each player has
extern int n_user;									//number of users


//play yard information
extern int cardhold[N_MAX_USER+1][N_MAX_CARDHOLD];	//cards that currently the players hold
extern int cardSum[N_MAX_USER];					//sum of the cards
extern int bet[N_MAX_USER];						//current betting 
extern int gameEnd; 							//game end flag
extern int stay;								// If you stop taking the Card


int getAction(void) {
	
	int i;
	int gostay;		// Determines whether the current user go or stop
	
//	switch(cardSum[0]) {
		
//		case 21:
//			break;
//		default:

	if(getCardNum(cardhold[0][0]) + getCardNum(cardhold[0][1]) == 21) {
		printf("(@>_<@)/\n   ::: Black Jack! Congratulation, You Win!! --> +$%d ($%d)\n\n", 2*bet[0], dollar[0]);
		stay++;		// Infinite Loop Protection
	}

	else if(cardSum[0] <= 21 && getCardNum(cardhold[0][0]) + getCardNum(cardhold[0][1]) != 21) {

		printf("The Sum of your Cards is %d\n", cardSum[0]);
		printf("   ::: Action? (0 - go, others - stay) : ");
		gostay = getIntegerInput();
		printf("\n");

		if(gostay == 0) {
			cardhold[0][Index[0]] = pullCard();
			Index[0]++;
		}
			
		else {
			stay++;
		}
	}
	
//			break;
//	}
	
/*	for(i = 1; i <= n_user; i++) {
		for(j = 0; j < 2; j++) {
			switch(cardhold[i][j]) {
				
				case 
			}
		}	
	}
	*/
	
//		else {
			
//		}

}


void printUserCardStatus(int user, int cardcnt) {
	
	int i;	
	
	printf("   -> card :");
	
//	cardhold[0][cardIndex] = pullCard();
	
	for(i = 0; i < cardcnt; i++)
		printCard(cardhold[user][i]);
		
	printf("\t ::: ");
}


// calculate the card sum and see if : 1. under 21, 2. over 21, 3. blackjack
int calcStepResult(int user) {

	int i, j, k;
//	int a[n_user];
//	int cardnum[n_user];
//	int a_num[n_user][3];
	
	// Calculate the Card Sum (including server)
//	for(i = 0; i <= n_user; i++) {
		
	// Card Sum, Ace, Dollar Reset
	cardSum[user] = 0;
	Ace[user] = 0;
//	dollar[i] = N_DOLLAR;
//	}

	for(j = 0; j < Index[user]; j++) {
		cardSum[user] += getCardNum(cardhold[user][j]);
		
		// The number of Ace
		if((cardhold[user][j] - 1) % 13 == 0) {
			Ace[user]++;
		}
	}
//	}
	
//	for(user = 0; user <= n_user; user++) {
	switch(Ace[user]) {
		case 0:
			// In case of over 21 when the Ace value is 1 or not selected
			if(cardSum[user] > 21) {
				dollar[user] -= bet[user];
			}
			break;
			
		case 1:
			// In case of BlackJack
			if(getCardNum(cardhold[user][0]) + getCardNum(cardhold[user][1]) == 21) {
				dollar[user] += 2 * bet[user];
			}
			
			// In case of over 21 when the Ace is 11
			else if(cardSum[user] > 21) {
				Ace[user]--;
				cardSum[user] -= 10;
			}
			break;
			
			// In case A is not selected
		case 2:
		case 3:
		case 4:
			if(cardSum[user] > 21) {
				Ace[user]--;
				cardSum[user] -= 10;
			}
			break;
		
		default:
			printf("***ERROR***");
			break;
	}
//	}
	
	// Calculate the score if the Card is A	
/*	for(i = 0; i < n_user; i++) {
		for(j = 1; j <= N_CARDSET*N_CARD; j + 13) {
			(cardnum[i] - 1) % 13 = 0;
			a_num[i] = getCardNum(j);
			a_num[i][(j - 1) / 13] = getCardNum(CardTray[j]);
		}
	}
	*/
	
/*	for(i = 0; i < N_MAX_USER; i++) {
		for(j = 1; j <= N_CARDSET*N_CARD; j + 13) {
			a_num[i][(j - 1) / 13] = getCardNum(CardTray[j]);
		}
	}
	*/
	
	
//	if(a1_num ==1 && cardSum[i]) {
//		cardSum[i] -= 10
//	}
	
//	num = (cardnum - 1) % 13;
		
//	switch(num) {
//		case 0:
//			s_num = 11;	

//	for(k = 0; k <= 3; k++)	{
/*		switch(a_num[0]) {
			case 11:
				// In case of BlackJack
				if(cardSum[0] == 21) {
					dollar[0] += 2 * bet[0];
				}
				
				// In case of over 21 when the Ace is 11
				else if(cardSum[0] > 21) {
					a_num[0] == 1;
					cardSum[0] -= 10;
				}
				break;
				
			case 1:
				// In case of over 21 when the Ace is 1
				if(cardSum[0] > 21) {
					dollar[0] -= bet[0];
				}
				break;
				
				// In case A is not selected
			default:
				if(cardSum[0] > 21) {
					dollar[0] -= bet[0];
				}
				break;
		}
	}
	*/
	
/*	for(k = 1; k <= n_user; k++) {
		while(cardSum[i] < 17) {

			// In case1 of BlackJack
			if(a_num == 11 && cardSum[0] = 21) {
						
			}
		
			// In case2 of under 21
			else if(a_num == 11 && cardSum[0] < 21) {
				getAction();
			}
		
			// In case3 of over 21
			else if(a_num == 11 && cardSum[0] > 21) {
				a_num -= 10
			}
		
			// In case4 of over 21
			else if(a_num == 1 && cardSum[0] > 21) {
			
			}
		}
	}
	*/

}

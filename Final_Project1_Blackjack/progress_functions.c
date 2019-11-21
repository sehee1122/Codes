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
extern int dollar[N_MAX_USER];
extern int n_user;

//play yard information
extern int cardhold[N_MAX_USER+1][N_MAX_CARDHOLD];
extern int cardSum[N_MAX_USER];
extern int bet[N_MAX_USER];
extern int gameEnd;
extern int stay;


int getAction(void) {
	
	int i;
	int gostay;		// Determines whether the current user go or stop

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
}


void printUserCardStatus(int user, int cardcnt) {
	
	int i;	
	
	printf("   -> card :");
	
	for(i = 0; i < cardcnt; i++)
		printCard(cardhold[user][i]);
		
	printf("\t ::: ");
}


// calculate the card sum and see if : 1. under 21, 2. over 21, 3. blackjack
int calcStepResult(int user) {

	int i, j, k;
		
	// Card Sum, Ace, Dollar Reset
	cardSum[user] = 0;
	Ace[user] = 0;

	for(j = 0; j < Index[user]; j++) {
		cardSum[user] += getCardNum(cardhold[user][j]);
		
		// The number of Ace
		if((cardhold[user][j] - 1) % 13 == 0) {
			Ace[user]++;
		}
	}
	
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
}


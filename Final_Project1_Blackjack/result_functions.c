#include "result_functions.h"

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


int checkResult(int user) {
	
	int i, j;
	int roundIndex = 1;

/////////////////////////////////////////////////
//////////// ERASE!!!!!!!!?????????????//////////
/*	int i, j, k;
	
	for(i = 1; i < n_user; i++) {
		printf(">>> player %d turn! ----------\n", i);
		printf("  -> card : ");
		
		for(j = 0; j < Index[i]; j++) {
//			printf("-> card : %d\t ::: GO!\n", cardhold[i][j]);
			
			printCard(cardhold[i][j]);
			calcStepResult();

//			if(getCardNum(cardhold[i]) < 21)
//			GO!
//			STAY!
//			DEAD (sum: 25)
		}
		printf("\t ::: \n\n");
	}
	
	printf(">>> server turn! ----------\n");
	printf("  -> card : ");
	
	for(j = 0; j < Index[n_user]; j++) {
		printCard(cardhold[n_user][j]);
	}
	printf("\n\n");
	*/
////////////////////////////////////////////////////////
	
	printf("\n\n-------------------- ROUND %d result ....\n", roundIndex);
	roundIndex += 1;

	for(user = 0; user < n_user; user++) {
		switch(user) {
			case 0:
				printf("  -> Your Result : ");
				break;
		
			default:	// else if(i > 0 && i < n_user)
				printf("  -> Result of Player %d : ", user);
				break;
		}
		
		if(cardSum[user] > 21) {
			printf("lose due to Overflow! ($%d)\n", dollar[user]);
		}
		
		else if(cardSum[user] >= cardSum[n_user]) {
			dollar[user] += bet[user];
			printf("win! :-) (sum: %d) --> $%d\n", cardSum[user], dollar[user]);
		}
		
		else if(cardSum[user] < cardSum[n_user]) {
			printf("lose! ;-( (sum: %d) --> $%d\n", cardSum[user], dollar[user]);
		}
		
		else {
			printf("***ERROR***\n");
		}
	}
}

int checkWinner() {

	int i, j;
	int winner[n_user];		// A game Winner
	int max_dollar;
	
	printf("Card ran out of the Tray!! Finishing the Game XD\n");
	
	for(i = 0; i < 3; i++) {
		printf("\n--------------------------------------------------");
	}
	printf("\n\nGame End! Your Money is $%d,\n\t  Players's Money is ", dollar[0]);
	
	// Find the player with the maximum dollars
	max_dollar = dollar[0];
	
	for(i = 1; i < n_user; i++) {
		printf("$%d ", dollar[i]);
		
		if(dollar[i] > max_dollar) {
			max_dollar = dollar[i];
		}
	}
	
	if(max_dollar == dollar[0]) {
		printf("\n\n�ڡ١ڡ١ڡ� You are the Winner! Congratulations! �١ڡ١ڡ١�\n");
	}
	
	else {
		for(i = 1; i < n_user; i++) {
			if(max_dollar == dollar[i]) {
				printf("\n\n�ڡ١ڡ١ڡ� The Winner is Player %d �١ڡ١ڡ١�\n", i);
			}
		}
	}
	
}

#include "player_functions.h"

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


//playing game functions -----------------------------
int cardIndex=0;
int stay=0;
int gamEnd=0;
//player settiing
int configUser(void) {

	int input;
	
	printf("Input the number of players (MAX:5): ");
	n_user = getIntegerInput();
	
	do {
		if(n_user > 5) {
			printf("Too many players!\n");
			printf("Input the number of players (MAX:5): ");
			scanf("%d", &n_user);
			fflush(stdin);
		}
	
		else if(n_user <= 0) {
			printf("invalid input players (%d)\n", n_user);
			printf("Input the number of players (MAX:5): ");
			scanf("%d", &n_user);
			fflush(stdin);
		}		
	} while(n_user <= 0 || n_user > 5);
	
	printf("--> card is mixed and put into the tray\n\n");
	
	return n_user;
}


//betting
int betDollar(void) {

	int input;
	
	printf("  -> your betting (total: $%d): ", dollar[0]);
	bet[0] = getIntegerInput();
	
	do {
		if(bet[0] > 50) {
			printf("  -> You only have $50! bet again\n");
			printf("  -> Your betting (total: $%d): ", dollar[0]);
			scanf("%d", &bet[0]);
			fflush(stdin);
		}
	
		else if(bet[0] <= 0) {
			printf("  -> invalid input for betting $(%d)\n", bet[0]);
			printf("  -> Your betting (total: $%d): ", dollar[0]);
			scanf("%d", &bet[0]);
			fflush(stdin);
		}		
	} while(bet[0] <= 0 || bet[0] > 50);
	
	return bet[0];
}


//offering initial 2 cards
void offerCards(void) {
	
	int i, j;
	
	//1. give two card for each players
	for (i = 0; i < n_user; i++) {
		cardhold[i][0] = pullCard();
		cardhold[i][1] = pullCard();
	}

	//2. give two card for the operator
		cardhold[n_user][0] = pullCard();
		cardhold[n_user][1] = pullCard();

	return;
}


//print initial card status
void printCardInitialStatus(void) {
	
	int i, j;
	
	for(i = 0; i <= n_user; i++) {
		Index[i] = 2;
	}
	
	printf("--- server		:   X ");
	printCard(cardhold[n_user][1]);
	printf("\n  -> you		: ");
	
	for(j = 0; j < Index[0]; j++) {
		printCard(cardhold[0][j]);
	}
	
	for(i = 1; i < n_user; i++) {
		printf("\n  -> player %d		: ", i);
		
		for(j = 0; j < Index[0]; j++) {
			printCard(cardhold[i][j]);
		}
	}
}


#include "card_functions.h"

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


//some utility functions

//get an integer input from standard input (keyboard)
//return : input integer value
//         (-1 is returned if keyboard input was not integer)
int getIntegerInput(void) {
    int input, num;
    
    num = scanf("%d", &input);
    fflush(stdin);		// Function to erase input buffers
    if (num != 1) //if it fails to get integer
        input = -1;
    
    return input;
}


//card processing functions ---------------

//calculate the actual card number in the blackjack game
int getCardNum(int cardnum) {
	
	int num;		// Card Number
	int score;		// The Value of the Card
	
	num = (cardnum - 1) % 13;
		
	switch(num) {
		case 0:
			score = 11;
			break;
		case 1:
			score = 10;
			break;
		case 2:
			score = 10;
			break;
		case 3:
			score = 10;
			break;
		default:
			score = num - 2;
	}
	
	return score;
}


//print the card information (e.g. DiaA)
void printCard(int cardnum) {
	
	int pattern;		// Card Pattern
	int number;			// Card Number
	
	pattern = (cardnum - 1) / 13;
	number = (cardnum - 1) % 13;
	
	switch(pattern) {
		case 0:
			printf("¢¾");	// heart
			break;
		case 1:
			printf("¡ß");	// diamond
			break;
		case 2:
			printf("¢¼");	// spade
			break;
		case 3:
			printf("¢À");	// club
			break;
		}
		
	switch(number) {
		case 0:
			printf("A ");	// Ace
			break;
		case 1:
			printf("J ");	// Jack
			break;
		case 2:
			printf("Q ");	// Queen
			break;
		case 3:
			printf("K ");	// King
			break;
		default:
			printf("%d ", number - 2);
			break;
	}
}


//card array controllers -------------------------------

//mix the card sets and put in the array
int mixCardTray(void) {
	
	srand(time(NULL));
	
	int ran_num = 0;	// Random Number
	int temp;		// For Mix the Cards
	int empty;		// Empty space
	int i, j;
	
/*	for(i = 0; i < 52; i++) {
	printCard(&cardnum, &i);
	getCardNum(&cardnum, &i);
	}
	*/
	
	// Unique number of each Card
	for(i = 0; i < N_CARDSET * N_CARD; i++) {
		
		CardTray[i] = i + 1;
	}
	
	// Random mixing of Cards
	for(j = 0; j < N_CARDSET * N_CARD; j++) {
		
		ran_num = rand() % (N_CARDSET * N_CARD);	// Generate random integers between 0 and N_CARD - 1
		temp = CardTray[j];
		CardTray[j] = CardTray[ran_num];
		CardTray[ran_num] = temp;
	}
}


//get one card from the tray
int pullCard(void) {
	
	cardIndex++;
	return CardTray[cardIndex];
}


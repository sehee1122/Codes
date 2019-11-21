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
extern int dollar[N_MAX_USER];						//dollars that each player has
extern int n_user;									//number of users


//play yard information
extern int cardhold[N_MAX_USER+1][N_MAX_CARDHOLD];	//cards that currently the players hold
extern int cardSum[N_MAX_USER];					//sum of the cards
extern int bet[N_MAX_USER];						//current betting 
extern int gameEnd; 							//game end flag
extern int stay;								// If you stop taking the Card


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
//			Ace[N_MAX_USER]++;
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

// int CardTray[N_CARD_PATTERN][N_CARD_NUMBER];
// int CardTray[N_CARDSET*N_CARD];
	
	pattern = (cardnum - 1) / 13;
	number = (cardnum - 1) % 13;

//	char *pptr[N_CARD_PATTERN] = {"♥", "◆", "♠", "♣"};
//	char *cptr[N_CARD_NUMBER] = {"A","2","3","4","5","6","7","8","9","10","J","Q","K"};	
	
	switch(pattern) {
		case 0:
			printf("♥");	// heart
			break;
		case 1:
			printf("◆");	// diamond
			break;
		case 2:
			printf("♠");	// spade
			break;
		case 3:
			printf("♣");	// club
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
		
/*		switch(number) {
			case 0:
				CardTray[][number] = "Ace";
				break;
			case 1:
				CardTray[][number] = "Jack";
				break;
			case 2:
				CardTray[][number] = "Queen";
				break;
			case 3:
				CardTray[][number] = "King";
				break;
			default:
				CardTray[][number] = number - 2;
		}
		*/
		
/*		switch(N_CARD_NUMBER) {
			case 0:
				CardTray[][N_CARD_NUMBER] = "Ace";
				break;
			case 1:
				CardTray[][N_CARD_NUMBER] = "Jack";
				break;
			case 2:
				CardTray[][N_CARD_NUMBER] = "Queen";
				break;
			case 3:
				CardTray[][N_CARD_NUMBER] = "King";
				break;
			default:
				CardTray[][N_CARD_NUMBER] = N_CARD_NUMBER + 1;
	}
	*/
		
/*	int i;
	char HRT, DIA, SPD, CLV;	// hearts, diamonds, spades, clubs
	int A;
	int J = 10;
	int Q = 10;
	int K = 10;
	*/
	
/*	int HRT[13];
	int DIA[13];
	int SPD[13];
	int CLV[13];
	int ran_card;
	char val;
	
	for(i = 1; i <= 9; i++) {
		val[i] = i + 1;
	}
	
	val[0] = A;
	val[10] = J;
	val[11] = Q;
	val[12] = K;
	*/
	
//	for(j = 0; j < 13; j++) {
//	printf("%d", val[j]);
	
/*	for(i = 0; i < 52; i++) {
		ran_card = rand() % 13 + 1;
		*cardnum[i] = ran_card;
	}
	*/
	
//	♡, ◇, ♧, ♤
// A 2 3 4 5 6 7 8 9 10 J Q K

// strlen : 문자열 길이 
// strcpy : 문자열 복사 
// strcat : 두 문자열 붙이기
// strcmp : 두 문자열 비교  

/*	char val[13];		// numerical value of each shape
	int num[9];
	int j;
	*/
	
/*	for(i = 0; i <= 8; i++) {
		num[i] = i + 2;
		sprintf(val[i + 1], "%d", num[i]);
	}
	*/
	
/*	for(i = 1; i <= 9; i++) {
		val[i] = i + 1;
	}
	
	val[0] = A;
	val[10] = J;
	val[11] = Q;
	val[12] = K;
	
	for(j = 0; j < 13; j++) {
	printf("%d", val[j]);
	}
	*/

//	printf("%d %d", 8 << 2 = 32, 8 >> 1 = 4);

/*	char A[40];
	char B[40];
	
	gets(A);
	gets(B);
	strcat(A, B);
	
	printf("%s\n", A);
	printf("%s\n", B);
	
	if(i = 1; i <= N_CARD >> 2; i++) {
		cardnum[i] = strcat()
	}
	
	else if(i = N_CARD + 1; i <= N_CARD >> 1; i++) {
		
	}
	
	else if(i = 2*N_CARD + 1; i <= N_CARD - (N_CARD >> 2); i++) {
		
	}
	
	else {
		
	}
	*/
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

//		printCard(&cardnum, &ran_num);
//		getCardNum(&cardnum, &ran_num);
//		*ptr = printCard(&cardnum, &ran_num);
	}
	
//	return CardTray;
	
//	mix_card[i] = rand() % 
	
/*	int i;
	
	for(i = 1; i <= 52; i++) {
		CardTray[i] 
	}

	for(j = 0; j < N_CARDSET * N_CARD; j++) {
		printf("%d\n", CardTray[j]);
	}
	*/
}


//get one card from the tray
int pullCard(void) {
	
//	int k;
//	int empty;

//	srand(time(NULL));
//	ran_num = rand() % N_CARD + 1;

	// The selected card is pushed to the end of the arrangement
/*	for(k = ran_num; k < N_CARDSET * N_CARD; k++) {
		
		if(k + 1 < N_CARDSET * N_CARD) {
			
			empty = CardTray[k];
			CardTray[k] = CardTray[k + 1];
			CardTray[k + 1] = empty;
		}
	}
	*/
	
	cardIndex++;
	
	return CardTray[cardIndex];
	
//	return CardTray[ran_num];
	
/*	printf("--- server		: X cardnum[i]");
	printf("  -> you		: X cardnum[i]");
	
	for(i = 1; i < n_user; i++)
		printf("  -> player	%d	: cardnum[j] cardnum[j]", i);
		*/
}

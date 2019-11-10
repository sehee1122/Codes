#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define N_CARDSET			1
#define N_CARD				52
#define N_DOLLAR			50


#define N_MAX_CARDNUM		13
#define N_MAX_USER			5
#define N_MAX_CARDHOLD		10
#define N_MAX_GO			17
#define N_MAX_BET			5

#define N_MIN_ENDCARD		30

/*
	Q1. main function 220 n_user, dollar가 한번에 통과되면 난수 생성 오류
		-> n_user, dollar 처음부터 잘 넣으면 난수 -> 값이 제대로 안나옴 
	Q2. user는 배팅 50까지 할 수 있는데 다른 player들은 N_MAX_BET인 5 까지밖에 못함
	(X) void printCard(int cardnum)
	(X) getCardNum 실제 카드번호 계산 어떤 함수?
	Q3. A는 처음에 1 or 11 결정해야 하는지  
	Q4. printf("  -> you		: ");
	printf("%d %d\n", mixCardTray(), mixCardTray());
	-> HRT3 CLVAce	11 3	(오른쪽에 숫자 나타나는 현상)
	 

*/


//card tray object
int CardTray[N_CARDSET*N_CARD];
int cardIndex = 0;							


//player info
int dollar[N_MAX_USER];						//dollars that each player has
int n_user;									//number of users


//play yard information
int cardhold[N_MAX_USER+1][N_MAX_CARDHOLD];	//cards that currently the players hold
int cardSum[N_MAX_USER];					//sum of the cards
int bet[N_MAX_USER];						//current betting 
int gameEnd = 0; 							//game end flag

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
int getCardNum(int *cardnum, int *i) {
	
	int num;
	int s_num;
	
	num = (*i - 1) % 13;
	
	switch(num) {
		case 0:
			printf("Ace\t");
			s_num = 11;
			break;
		case 1:
			printf("Jack\t");
			s_num = 10;
			break;
		case 2:
			printf("Queen\t");
			s_num = 10;
			break;
		case 3:
			printf("King\t");
			s_num = 10;
			break;
		default:
			printf("%d\t", num + 1);
			s_num = num + 1;
	}
	
	return s_num;
}

//print the card information (e.g. DiaA)
void printCard(char *cardnum[N_CARD], int *i) {
	
	int pattern;
	
	pattern = (*i - 1) / 13;
	
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
	
	int cardnum;
	int mix_card;
	int ran_num;		// nth Card
	
/*	for(i = 0; i < 52; i++) {
	printCard(&cardnum, &i);
	getCardNum(&cardnum, &i);
	}
	*/
	
	ran_num = rand() % 52 + 1;
	
	printCard(&cardnum, &ran_num);
	getCardNum(&cardnum, &ran_num);
	
//	mix_card[i] = rand() % 
	
/*	int i;
	
	for(i = 1; i <= 52; i++) {
		CardTray[i] 
	}
	*/
}

//get one card from the tray
int pullCard(void) {
	
//	int cardhold[N_MAX_USER+1][N_MAX_CARDHOLD];
	
	mixCardTray();

/*	int i;
	//1. give two card for each players
	for (i = 0; i < n_user; i++) {
		cardhold[i][0] = pullCard();
		cardhold[i][1] = pullCard();
	}

	//2. give two card for the operator
		cardhold[n_user][0] = pullCard();
		cardhold[n_user][1] = pullCard();		
	*/
	
/*	printf("--- server		: X cardnum[i]");
	printf("  -> you		: X cardnum[i]");
	
	for(i = 1; i < n_user; i++)
		printf("  -> player	%d	: cardnum[j] cardnum[j]", i);
		*/
}


//playing game functions -----------------------------

//player settiing
int configUser(void) {
	int n_user;
	int input;
	
	printf("Input the number of players (MAX:5): ");
	scanf("%d", &n_user);
	fflush(stdin);
	
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
	
	// when num is a character
		else {
/*			printf("invalid input players (-1)\n");
			printf("Input the number of players (MAX:5): ");
			scanf("%d", &num);
			fflush(stdin);
			*/
			input = getIntegerInput();
			printf("%d", &input);
		}
	} while(n_user <= 0 || n_user > 5);
	
	printf("--> card is mixed and put into the tray\n\n");
	
	return n_user;
}



//betting
int betDollar(void) {
	int dollar;
	int input;
	
	printf("  -> your betting (total: $50): ");
	scanf("%d", &dollar);
	fflush(stdin);
	
	do {
		if(dollar > 50) {
			printf("  -> You only have $50! bet again\n");
			printf("  -> Your betting (total: $50): ");
			scanf("%d", &dollar);
			fflush(stdin);
		}
	
		else if(dollar < 0) {
			printf("  -> invalid input for betting $(%d)\n", dollar);
			printf("  -> Your betting (total: $50): ");
			scanf("%d", &dollar);
			fflush(stdin);
		}
	
	// when dollar is a character
		else {
			input = getIntegerInput();
			printf("%d", &input);
		}
	} while(dollar < 0 || dollar > 50);
	
	return dollar;
}


//offering initial 2 cards
void offerCards(void) {
	int i;
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
	
}

int getAction(void) {
	
}


void printUserCardStatus(int user, int cardcnt) {
	int i;
	
	printf("   -> card : ");
	for (i=0;i<cardcnt;i++)
//		printCard(cardhold[user][i]);
	printf("\t ::: ");
}




// calculate the card sum and see if : 1. under 21, 2. over 21, 3. blackjack
int calcStepResult() {
	
	int i;		// Number of users
	int j;		// Number of cards for each user
	
	// 1. calculate the sum of each player's cards
	for(i = 0; i < n_user; i++) {
		for(j = 0; j <= 1; j++) {
			cardSum[i] = cardhold[i][j];
		}
	}
	
	// 2. calculate the sum of the operator's cards
	
	for(j = 0; j <= 1; j++) {
		cardSum[n_user] = cardhold[n_user][j];
	}
}

int checkResult() {
	
}

int checkWinner() {
	
}



int main(int argc, char *argv[]) {
	
	int roundIndex = 0;
	int max_user;
	int i, j;
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
	
	printf("-----------------------------------------\n");
	printf("--------- ROUND 1 (cardIndex:0) ---------\n");
	printf("-----------------------------------------\n\n");

	//Game initialization --------
	//1. players' dollar
	printf("------------- BETTING STEP -------------\n");
	bet[0] = betDollar();	
	
	for(i = 1; i <= n_user - 1; i++) {
		bet[i] = rand() % N_MAX_BET + 1;
		printf("  -> player%d bets $%d (out of $50)\n", i, bet[i]);
	}

	printf("----------------------------------------\n\n");

	//2. card tray
	printf("------------- CARD OFFERING -------------\n");
	
/*	printf("--- server		: %d %d\n", mixCardTray(), mixCardTray());
	printf("  -> you		: %d %d\n", mixCardTray(), mixCardTray());
	printf("  -> player 1	: %d %d\n", mixCardTray(), mixCardTray());
	printf("  -> player 2	: %d %d\n\n", mixCardTray(), mixCardTray());
	*/
/*	for (i = 0; i < n_user; i++) {
		cardhold[i][0] = pullCard();
		cardhold[i][1] = pullCard();
	}

	//2. give two card for the operator
		cardhold[n_user][0] = pullCard();
		cardhold[n_user][1] = pullCard();
		
		offerCards
		*/
	
	printf("--- server		: X\t");
	printf("%d\n", offercards());
	printf("  -> you		: ");
	printf("%d\t%d\n", mixCardTray(), mixCardTray());
	
	for(j = 1; j <= n_user - 1; j++) {
	printf("  -> player %d		: ", j);
	printf("%d\t%d\n", mixCardTray(), mixCardTray());
	}

	//Game start --------
//	do {
		
//		betDollar();
		offerCards(); //1. give cards to all the players
		
/*		printCardInitialStatus();
		printf("\n------------------ GAME start --------------------------\n");
		
		//each player's turn
		for () //each player
		{
			while () //do until the player dies or player says stop
			{
				//print current card status printUserCardStatus();
				//check the card status ::: calcStepResult()
				//GO? STOP? ::: getAction()
				//check if the turn ends or not
			}
		}
		
		//result
		checkResult();
	} while (gameEnd == 0);
	
	checkWinner();
	
*/	
	return 0;
}

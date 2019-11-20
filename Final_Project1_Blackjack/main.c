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

// #define	N_CARD_PATTERN		4
// #define N_CARD_NUMBER		13

/*
	Q1. main function 220 n_user, dollar가 한번에 통과되면 난수 생성 오류
		-> n_user, dollar 처음부터 잘 넣으면 난수 -> 값이 제대로 안나옴
		-> getIntegerInput function 사용 
	Q2. user는 배팅 50까지 할 수 있는데 다른 player들은 N_MAX_BET인 5 까지밖에 못함
	(X) void printCard(int cardnum)
	(X) getCardNum 실제 카드번호 계산 어떤 함수?
	Q3. A는 처음에 1 or 11 결정해야 하는지
		-> 나중에 21이 초과되는지에 따라 A의 값이 다르게 설정 (11 -> 1) 
	Q4. printf("  -> you		: ");
	printf("%d %d\n", mixCardTray(), mixCardTray());
	-> HRT3 CLVAce	11 3	(오른쪽에 숫자 나타나는 현상)
	
	player 수 정함
 	-> dollar 나눠줌
	-> 카드 섞어서 tray에 넣음
	-> round 반복 {
	-> 배팅
	-> 두장 씩 나눠줌 
	-> player 별로 turn (반복 - for문)
		-> (반복) go? stop? 
			-> (반복) 3중 반복문이 되어야함
	-> round 결과 도출 (최종 승리자 결정); 
	}
	
	@ 승패 조건
	고려사항 1) 블랙잭일 경우 -> 무조건 승리
	고려사항 2) 한 장 이상 카드를 추가로 받아서 21이 넘었을 경우 -> 패배
	
	turn이 모두 종료되면 승/패
	
	나+딜러가 모두 블랙잭 / 21이 넘었을 경우,
	언제 결정이 되는지 알아보고
	나는 무조건 승 / 패 (딜러 상관 x) 
	 

*/


//card tray object
int CardTray[N_CARDSET*N_CARD];
// int CardTray[N_CARD_PATTERN][N_CARD_NUMBER];
int cardIndex = 0;
int Index[N_MAX_USER];
int Ace[N_MAX_USER];			


//player info
int dollar[N_MAX_USER];						//dollars that each player has
int n_user;									//number of users


//play yard information
int cardhold[N_MAX_USER+1][N_MAX_CARDHOLD];	//cards that currently the players hold
int cardSum[N_MAX_USER];					//sum of the cards
int bet[N_MAX_USER];						//current betting 
int gameEnd = 0; 							//game end flag
int stay = 0;								// If you stop taking the Card

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

static int ran_num = 0;	// Random Number

//mix the card sets and put in the array
int mixCardTray(void) {
	
	srand(time(NULL));
	
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


//playing game functions -----------------------------

//player settiing
int configUser(void) {

	int input;
	
	printf("Input the number of players (MAX:5): ");
//	scanf("%d", &n_user);
//	fflush(stdin);
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
	
	// when num is a character
/*		else {
			printf("invalid input players (-1)\n");
			printf("Input the number of players (MAX:5): ");
			scanf("%d", &num);
			fflush(stdin);
			input = getIntegerInput();
			printf("%d", &input);
		}
		*/
		
	} while(n_user <= 0 || n_user > 5);
	
	printf("--> card is mixed and put into the tray\n\n");
	
	return n_user;
}



//betting
int betDollar(void) {

	int input;
	
	printf("  -> your betting (total: $%d): ", dollar[0]);
//	scanf("%d", &dollar);
//	fflush(stdin);
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
	
	// when dollar is a character
/*		else {
			input = getIntegerInput();
			printf("%d", &input);
		}
		*/
		
	} while(bet[0] < 0 || bet[0] > 50);
	
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
	
//	for(j = 0; j < n_user; j++) {
//	}
	
	// --------------------------------------------------
	// Avoid redundancy if random numbers are created equal
	// --------------------------------------------------
	
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
//	printf("%d\n", cardhold[n_user][1]);
	printf("\n  -> you		: ");
	
	for(j = 0; j < Index[0]; j++) {
		printCard(cardhold[0][j]);
//	printf("%d\t%d\n", printcard(cardhold[0][0]), printcard(cardhold[0][1]));
	}
	
	for(i = 1; i < n_user; i++) {
		printf("\n  -> player %d		: ", i);
		
		for(j = 0; j < Index[0]; j++) {
			printCard(cardhold[i][j]);
//		printf("%d\t%d\n", cardhold[i][0], cardhold[i][1]);
		}
	}
}

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
	for(i = 0; i <= n_user; i++) {
		
		// Card Sum, Ace, Dollar Reset
		cardSum[i] = 0;
		Ace[i] = 0;
		dollar[i] = N_DOLLAR;
		
		for(j = 0; j < Index[0]; j++) {
			cardSum[i] += getCardNum(cardhold[i][j]);
			
			// The number of Ace
			if((cardhold[i][j] - 1) % 13 == 0) {
				Ace[i]++;
			}
		}
	}
	
	for(user = 0; user <= n_user; user++) {
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

int checkResult() {
	
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

	for(i = 0; i <= n_user; i++) {
		switch(i) {
			case 0:
				printf("  -> your result : ");
				break;
		
			default:	// else if(i > 0 && i < n_user)
				printf("  -> player %d result : ", i);
				break;
		}
		
		if(cardSum[i] > 21) {
			printf("lose due to Overflow! ($%d)\n", dollar[i]);
		}
		
		else if(cardSum[i] >= cardSum[n_user]) {
			printf("win! :-) (sum: %d) --> $%d\n", cardSum[i], dollar[i]);
		}
		
		else if(cardSum[i] < cardSum[n_user]) {
			printf("lose! ;-( (sum: %d) --> $%d\n", cardSum[i], dollar[i]);
		}
		
		else {
			printf("***ERROR***\n");
		}
	}
}

int checkWinner() {

	int i;
	int winner;		// A game Winner
	
	printf("\nCard ran out of the Tray!! Finishing the Game XD\n");
	
	for(i = 0; i < 3; i++) {
		printf("\n--------------------------------------------------");
	}
	
	printf("\n\nGame End! Your Money is $%d, Players's' Money is ");
	
	for(i = 1; i < n_user; i++) {
		printf("$%d ", dollar[i]);
	}
	
	
	
	printf("\n\n★☆★☆★☆ Winner is %d ☆★☆★☆★\n", winner);
}


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
	
	int ran_num;
	int cardnum;
	
//	for(ran_num = 1; ran_num <= 52; ran_num++) {

//		printf("%d\n", printCard(&cardnum, &ran_num));
//	}
	
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
		
		printf("-----------------------------------------\n");
		printf("--------- ROUND %d (cardIndex: %d) ---------\n", roundIndex, cardIndex);
		printf("-----------------------------------------\n\n");
		
		offerCards(); //1. give cards to all the players
		
		printf("------------- BETTING STEP -------------\n");
		bet[0] = betDollar();
		
		for(i = 1; i < n_user; i++) {
			bet[i] = rand() % N_MAX_BET + 1;
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
		for(i = 0; i < n_user; i++) //each player
		{
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
		}
		
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
				printf("GO!\n");
				
				cardhold[i][Index[i]] = pullCard();
				cardSum[i] += cardhold[i][Index[i]];
				Index[i]++;
			}
			
			if(cardSum[i] > 17) {
				printUserCardStatus(i, Index[i]);
				calcStepResult(i);
				
				if(getCardNum(cardhold[i][0]) + getCardNum(cardhold[i][1]) == 21) {	
					printf("(@>_<@)/\n   ::: Black Jack! Congratulation, You Win!! --> +$%d ($%d)\n\n", 2*bet[i], dollar[i]);
				}
				
				else if(cardSum[i] <= 21 && getCardNum(cardhold[i][0]) + getCardNum(cardhold[i][1]) != 21) {
					printf("STAY!\n\n");
				}
			
				else if(cardSum[i] > 21) {
					printf("OTL\n   ::: DEAD (sum: %d) --> -$%d ($%d)\n\n", cardSum[i], bet[i], dollar[i]);
				}
				
				else {
					printf("***ERROR***\n");
				}
			}
			
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
		checkResult();
		
		if(cardIndex > 52) {
			gameEnd++;
		}
		
	} while (gameEnd == 0 && cardIndex <= 52);
	
	gameEnd++;		// A virtually unnecessary part
	checkWinner();

	return 0;
}

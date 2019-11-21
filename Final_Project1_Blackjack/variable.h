#ifndef _VARIABLE_H
#define _VARIABLE_H

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


//card tray object
int CardTray[N_CARDSET*N_CARD];
// int CardTray[N_CARD_PATTERN][N_CARD_NUMBER];
int cardIndex;
int Index[N_MAX_USER];
int Ace[N_MAX_USER];			


//player info
int dollar[N_MAX_USER];						//dollars that each player has
int n_user;									//number of users


//play yard information
int cardhold[N_MAX_USER+1][N_MAX_CARDHOLD];	//cards that currently the players hold
int cardSum[N_MAX_USER];					//sum of the cards
int bet[N_MAX_USER];						//current betting 
int gameEnd; 							//game end flag
int stay;								// If you stop taking the Card

#endif

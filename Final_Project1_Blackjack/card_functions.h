#ifndef _CARD_H
#define _CARD_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>


//some utility functions
int getIntegerInput(void);

//card processing functions ---------------

//calculate the actual card number in the blackjack game
int getCardNum(int cardnum);
//print the card information (e.g. DiaA)
void printCard(int cardnum);

//card array controllers -------------------------------

//mix the card sets and put in the array
int mixCardTray(void);
//get one card from the tray
int pullCard(void);

#endif


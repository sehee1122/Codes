#ifndef _PLAYER_H
#define _PLAYER_h

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>


//playing game functions -----------------------------

//player settiing
int configUser(void);
//betting
int betDollar(void);
//offering initial 2 cards
void offerCards(void);
//print initial card status
void printCardInitialStatus(void);

#endif

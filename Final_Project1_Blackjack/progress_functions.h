#ifndef _PROGRESS_H
#define _PROGRESS_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>


int getAction(void);
void printUserCardStatus(int user, int cardcnt);
int calcStepResult(int user);

#endif

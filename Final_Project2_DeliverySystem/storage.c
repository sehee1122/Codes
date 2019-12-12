#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>				// String-separating strtok function
#include "storage.h"

/* 
  definition of storage cell structure ----
  members :
  int building : building number of the destination
  int room : room number of the destination
  int cnt : number of packages in the cell
  char passwd[] : password setting (4 characters)
  char *contents : package context (message string)
*/

typedef struct {
	int building;
	int room;
	int cnt;
	char passwd[PASSWD_LEN + 1];
	
	char *context;
} storage_t;

static storage_t** deliverySystem; 			//deliverySystem
static int storedCnt = 0;					//number of cells occupied
static int systemSize[2] = {0, 0};  		//row/column of the delivery system
static char masterPassword[PASSWD_LEN + 1];	//master password


// ------- inner functions ---------------

//print the inside context of a specific cell
//int x, int y : cell to print the context
static void printStorageInside(int x, int y) {
	printf("\n------------------------------------------------------------------------\n");
	printf("------------------------------------------------------------------------\n");

	if (deliverySystem[x][y].cnt > 0)
		printf("<<<<<<<<<<<<<<<<<<<<<<<< : %s >>>>>>>>>>>>>>>>>>>>>>>>>>>>\n", deliverySystem[x][y].context);
	else
		printf("<<<<<<<<<<<<<<<<<<<<<<<< empty >>>>>>>>>>>>>>>>>>>>>>>>>>>>\n");
		
	printf("------------------------------------------------------------------------\n");
	printf("------------------------------------------------------------------------\n\n");
}


//initialize the storage
//set all the member variable as an initial value
//and allocate memory to the context pointer
//int x, int y : cell coordinate to be initialized
static void initStorage(int x, int y) {

	deliverySystem[x][y].building = 0;
	deliverySystem[x][y].room = 0;
	deliverySystem[x][y].cnt = 0;
	deliverySystem[x][y].passwd[0] = '\0';
	deliverySystem[x][y].context = '\0';
}


//get password input and check if it is correct for the cell (x,y)
//int x, int y : cell for password check
//return : 0 - password is matching, -1 - password is not matching
static int inputPasswd(int x, int y) {
	
	char passwd[PASSWD_LEN + 1];
	
	printf("input password for (%i, %i) storage : ", x, y);
	scanf("%4s", passwd);			// PASSWD_LEN = 4
	fflush(stdin);

	if(strcmp(deliverySystem[x][y].passwd, passwd) != 0) {
		return -1;
	}
	return 0;
}


// ------- API function for main.c file ---------------

//backup the delivery system context to the file system
//char* filepath : filepath and name to write
//return : 0 - backup was successfully done, -1 - failed to backup
int str_backupSystem(char* filepath) {

	int x, y;

	FILE *fp = fopen(filepath, "w");	// open the "storage.txt" file in write mode

//	Failed to backup
	if(fp == NULL) {
		return -1;
	}
//	Backup was successfully done
	else {
		fprintf(fp, "%d %d\n", systemSize[0], systemSize[1]);	// row, column in storage box
		fprintf(fp, "%s\n", masterPassword);	// Master key

		for(x = 0; x < systemSize[0]; x++) {
			for(y = 0; y < systemSize[1]; y++) {
				if(deliverySystem[x][y].cnt != 0) {
					fprintf(fp, "%d %d %d %d %s %s\n", x, y, deliverySystem[x][y].building, deliverySystem[x][y].room, deliverySystem[x][y].passwd, deliverySystem[x][y].context);
				}
			}
		}
		fclose(fp);
	}
	return 0;	// close file pointer
}


//create delivery system on the double pointer deliverySystem
//char* filepath : filepath and name to read config parameters (row, column, master password, past contexts of the delivery system)
//return : 0 - successfully created, -1 - failed to create the system
int str_createSystem(char* filepath) {

	int i;
	int x, y;
	
	FILE *fp;						// fp: File Pointer
	fp = fopen(filepath, "r");		// Open the "storage.txt" file in read mode(r)
	
//	Failed to create the system
	if(fp == NULL) {
		return -1;
	}
//	System was Successfully created
	else {
		fscanf(fp, "%d %d", &systemSize[0], &systemSize[1]);	// row, column in storage box
		fscanf(fp, "%s", masterPassword);						// Master key

/*		Outline: Double pointer Dynamic Allocation

		int i;
		int **m = malloc(sizeof(int *) * x);
		
		for(i = 0; i < x; i++) {				
			m[i] = malloc(sizeof(int) * y);
		}
*/
		// Allocate (int pointer size * length size) of dynamic memory to double pointer
		// length of an array.
		deliverySystem = (storage_t **)malloc(sizeof(storage_t*) * systemSize[0]);
	
		// Allocate (int pointer size * horizontal size) of dynamic memory by double pointer
		// width of the array
		for(i = 0; i < systemSize[0]; i++) {
			deliverySystem[i] = (storage_t*)malloc(sizeof(storage_t) * systemSize[1]);
		}
		
		for(x = 0; x < systemSize[0]; x++) {
			for(y = 0; y < systemSize[1]; y++) {
				initStorage(x, y);
			}
		}

		// (X) Setting the initial value(Reset) when the file is finished reading
		// If the input file is valid
		// Unless it's the end of the file
		while(EOF != fscanf(fp, "%d %d", &x, &y)) {
			deliverySystem[x][y].context = (char*)malloc(sizeof(char) * (MAX_MSG_SIZE + 1));
			fscanf(fp, "%d %d %s %s", &deliverySystem[x][y].building, &deliverySystem[x][y].room, deliverySystem[x][y].passwd, deliverySystem[x][y].context);
			deliverySystem[x][y].cnt++;
			storedCnt++;
		}
		fclose(fp);		// close file pointer
	}
	return 0;
}


//free the memory of the deliverySystem 
void str_freeSystem(void) {
	
	int i;
	int x, y;
	
	for(i = 0; i < systemSize[0]; i++) {
		free(deliverySystem[i]);
	}
	free(deliverySystem);
	
	for(x = 0; x < systemSize[0]; x++) {
		for(y = 0; y < systemSize[1]; y++) {
			free(deliverySystem[x][y].context);
		}
	}
}


//print the current state of the whole delivery system (which cells are occupied and the destination of the each occupied cells)
void str_printStorageStatus(void) {
	int i, j;
	printf("----------------------------- Delivery Storage System Status (%i occupied out of %i )-----------------------------\n\n", storedCnt, systemSize[0]*systemSize[1]);
	
	printf("\t");
	for (j = 0; j < systemSize[1]; j++)
	{
		printf(" %i\t\t", j);
	}
	printf("\n-----------------------------------------------------------------------------------------------------------------\n");
	
	for (i = 0; i < systemSize[0]; i++)
	{
		printf("%i|\t", i);
		for (j = 0; j < systemSize[1]; j++)
		{
			if (deliverySystem[i][j].cnt > 0)
			{
				printf("%i, %i\t|\t", deliverySystem[i][j].building, deliverySystem[i][j].room);
			}
			else
			{
				printf(" -  \t|\t");
			}
		}
		printf("\n");
	}
	printf("--------------------------------------- Delivery Storage System Status --------------------------------------------\n\n");
}


//check if the input cell (x,y) is valid and whether it is occupied or not
int str_checkStorage(int x, int y) {
	if (x < 0 || x >= systemSize[0])
	{
		return -1;
	}
	
	if (y < 0 || y >= systemSize[1])
	{
		return -1;
	}
	
	return deliverySystem[x][y].cnt;
}


//put a package (msg) to the cell
//input parameters
//int x, int y : coordinate of the cell to put the package
//int nBuilding, int nRoom : building and room numbers of the destination
//char msg[] : package context (message string)
//char passwd[] : password string (4 characters)
//return : 0 - successfully put the package, -1 - failed to put
int str_pushToStorage(int x, int y, int nBuilding, int nRoom, char msg[MAX_MSG_SIZE+1], char passwd[PASSWD_LEN+1]) {

	initStorage(x, y);
	
	deliverySystem[x][y].building = nBuilding;
	deliverySystem[x][y].room = nRoom;
	deliverySystem[x][y].cnt++;						// deliverySystem[x][y].cnt == 1;
	strcpy(deliverySystem[x][y].passwd, passwd);	// strcpy(target, original string): copy string
	deliverySystem[x][y].context = msg;

	// Failed to put
	if(deliverySystem[x][y].cnt == 0) {
		printf("Failed to put the package\n");
		return -1;
	}
	// Package was Successfully put
	else {
		storedCnt++;
		return 0;
	}
}


//extract the package context with password checking
//after password checking, then put the msg string on the screen and re-initialize the storage
//int x, int y : coordinate of the cell to extract
//return : 0 - successfully extracted, -1 = failed to extract
int str_extractStorage(int x, int y) {
	
	char att_passwd[PASSWD_LEN + 1];	// Password attempted by user
	
	printf(" - input password for (%d, %d) storage : ", x, y);
	scanf("%4s", &att_passwd);		// because of PASSWD_LEN = 4
	fflush(stdin);

	if((strcmp(deliverySystem[x][y].passwd, att_passwd) && strcmp(masterPassword, att_passwd)) != 0) {
		printf("----------> Password is Wrong! OTL\n");		
		return -1;
	}
	
	else {
		printf("----------> Extracting the storage (%d, %d)...\n", x, y);
		printStorageInside(x, y);
		initStorage(x, y);
		storedCnt--;
		free(deliverySystem[x][y].context);
		return 0;
	}
}


//find my package from the storage
//print all the cells (x,y) which has my package
//int nBuilding, int nRoom : my building/room numbers
//return : number of packages that the storage system has
int str_findStorage(int nBuilding, int nRoom) {
	
	int x, y;					// x = row, y = column of the delivery system
	int cnt = 0;
	
	// Print all the cells (x,y) which has my package
	for(x = 0; x < systemSize[0]; x++) {
		for(y = 0; y < systemSize[1]; y++) {

			if((deliverySystem[x][y].building == nBuilding) && (deliverySystem[x][y].room == nRoom)) {

				printf(" ---------> Found a package in (%i, %i)\n", x, y);
				cnt++;	// Number of packages found
			}
		}
	}
	return cnt;
}


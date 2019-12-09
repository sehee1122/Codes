#include <stdio.h>
#include <stdlib.h>
#include <string.h>
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
	
	// 1. set all the member variable as an initial value
	// Hint: x, y를 지정해주는 경우는 한 칸에 대한 내용에 대해서만 코딩할 확률이 높음 
	struct istorage_t storage_box = {0, };		// struct 'StructureName' 'VariableName'
	deliverySystem[x][y] = storage_box;		// Initialize all contents of structure variable to zero
	
//	struct storage_t storage
//	X Y를 쓰자 바보야 
	
/*	storage_t = {
		.building = "0",
		.room = "0",
		.cnt = "0",
		.passwd[PASSWD_LEN+1] = "0"	// ???!
	};
*/
	
	// 2. allocate memory to the context pointer
	int *pi = NULL;
	pi = (int *)malloc(sizeof(int));
	
	if(pi == NULL) {
		printf("Memory allocation error: %p\n", *pi);
		exit(1);
	}
	
	// 3. int x, int y : cell coordinate to be initialized
	deliverySystem[x][y] = storage_box;
}

//get password input and check if it is correct for the cell (x,y)
//int x, int y : cell for password check
//return : 0 - password is matching, -1 - password is not matching
static int inputPasswd(int x, int y) {
	
	char passwd[PASSWD_LEN + 1];
	
	// 1. get password input and check if it is correct for the cell (x,y)
	printf("input password for (%i, %i) storage : ", x, y);
	scanf("%4s", &passwd);
	fflush(stdin);
/*	printf("input password for (row, column) storage : %d", storage_t.passwd);
	storage_t.passwd = 
	passwd[PASSWD_LEN+1];
*/
	
	// 2. int x, int y : cell for password check
//	initStorage
	
	// 3. return : 0 - password is matching, -1 - password is not matching
	if(strcmp(deliverySystem[x][y].passwd, storage_box.passwd) != 0) {
		return -1;
	}
	return 0;
}


// ------- API function for main.c file ---------------

//backup the delivery system context to the file system
//char* filepath : filepath and name to write
//return : 0 - backup was successfully done, -1 - failed to backup
int str_backupSystem(char* filepath) {
	
	// 1. backup the delivery system context to the file system
	char backup[MAX_MSG_SIZE];
	
	// 2. char* filepath : filepath and name to write
	FILE *fp = fopen("storage.txt", "w");		// open the "storage.txt" file in write mode
/*	FILE *fp;
	fp = fopen("storage.txt", "r");
	char *tmp = "123456789";
*/

	fgets(backup, sizeof(backup), fp);
	printf("%s\n", backup);				// print the contents of a file

/*	strcpy(backup, tmp);				// strcpy(): copy up to NULL at the end of the string
*/	
	
	// 3. return : 0 - backup was successfully done, -1 - failed to backup
	if(fp == NULL) {
		printf("Failed to backup\n");
		return -1;
	}
	else {
		printf("Backup was successfully done\n");
		return 0;
	}
	
	fclose(fp);							// close file pointer
}


//create delivery system on the double pointer deliverySystem
//char* filepath : filepath and name to read config parameters (row, column, master password, past contexts of the delivery system)
//return : 0 - successfully created, -1 - failed to create the system
int str_createSystem(char* filepath) {

	int i;
	int x, y;
	
	// Outline
/*	int i;
	int **m = malloc(sizeof(int *) * x);
	
	for(i = 0; i < x; i++) {				
		m[i] = malloc(sizeof(int) * y);
	}
*/
	
	// 2. char* filepath : filepath and name to read config parameters
	//	- row, column, master password, past contexts of the delivery system
	FILE *fp = fopen("storage.txt", "r");	// Open the "storage.txt" file in read mode(r)
											// fp: File Pointer

	// 3. return : 0 - successfully created, -1 - failed to create the system
	if(fp == NULL) {
		printf("Failed to create the system\n");
		return -1;
	}
	else {
		fscanf(fp, "%d %d", systemSize[0], systemSize[1]);	// row, column in storage box
		fscanf(fp, "%s", masterPassword[PASSWD_LEN + 1]);	// Master key
		
	// 1. create delivery system on the double pointer deliverySystem
		// Allocate (int pointer size * length size) of dynamic memory to double pointer
		// length of an array.
		deliverySystem = (storage_t **)malloc(sizeof(storage_t *) * systemSize[0]);
		
		// Allocate (int pointer size * horizontal size) of dynamic memory by double pointer
		// width of the array
		for(i = 0; i < systemSize[0]; i++) {
			deliverySystem[i] = malloc(sizeof(storage_t) * systemSize[1]);
		}
		
		// Setting the initial value(Reset) when the file is finished reading
		if(feof(fp) == 0) {				// feof: End-of-File indicator
			storage_t storage_box = {0, };
			
			// context is pointer
			fscanf(fp, "%d %d %d %d %s %s", &x, &y, &deliverySystem[x][y].building, &deliverySystem[x][y].room, &deliverySystem[x][y].passwd[0], deliverySystem[x][y].context);	
			if(deliverySystem[x][y].context != NULL) {
				deliverySystem[x][y].cnt++;
				storedCnt++;
			}
			storage_box = deliverySyetem[x][y];
		}
//		printf("System was successfully created\n");
		return 0;
	}
	fclose(fp);							// close file pointer
	
	return 0;
}


//free the memory of the deliverySystem 
void str_freeSystem(void) {
	
	int x, y;
	
	for(x = 0; x < systemSize[0]; x++) {
		for(y = 0; y < systemSize[1]; y++) {
			free(deliverySystem[x][y]);
		}
	}
}


//print the current state of the whole delivery system (which cells are occupied and the destination of the each occupied cells)
void str_printStorageStatus(void) {
	int i, j;
	printf("----------------------------- Delivery Storage System Status (%i occupied out of %i )-----------------------------\n\n", storedCnt, systemSize[0]*systemSize[1]);
	
	printf("\t");
	for (j=0; j < systemSize[1]; j++)
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

//	FILE *rfp = fopen("storage.txt", "r");
//	FILE *wfp = fopen("storage.txt", "w");
	
	storage_box.building = nBuilding;
	storage_box.room = nRoom;
	strcpy(storage_box.passwd, passwd);	// strcpy(target, original string): copy string
	storage_box.context = msg;
	
	if(storage_box.context != NULL) {
		storage_box.cnt++;
	}
	deliverySystem[x][y] = storage_box;
	
	// 1. put a package (msg) to the cell
//	str_checkStorage(int storage_box.x, int storage_box.y);
	
//	fscanf(rfp, "%d %d %d %d %s %s");
//	fprintf(wfp, "%d %d %d %d %s %s\n");

	// 2. input parameters
	
	// 3. int x, int y : coordinate of the cell to put the package

	// 4. int nBuilding, int nRoom : building and room numbers of the destination
	
	// 5. char msg[] : package context (message string)
//	char msg[MAX_MSG_SIZE];

	// 6. char passwd[] : password string (4 characters)
//	char passwd[PASSWD_LEN];

	// 7. return : 0 - successfully put the package, -1 - failed to put
	if(deliverySystem[x][y].cnt == NULL) {
		printf("Failed to put the package\n");
		return -1;
	}
	else {
		printf("Package was successfully put\n");
		storedCnt++;
		return 0;
	}
//	fclose(rfp);							// close file pointer
//	fclose(wfp);							// close file pointer
}


//extract the package context with password checking
//after password checking, then put the msg string on the screen and re-initialize the storage
//int x, int y : coordinate of the cell to extract
//return : 0 - successfully extracted, -1 = failed to extract
int str_extractStorage(int x, int y) {
	// 1. extract the package context with password checking
	if(inputPasswd(x, y) == 0) {
		printf("----------> Extracting the storage (%i, %i)...\n\n", x, y);
		printf("--------------------------------------------------\n");
		printf("--------------------------------------------------\n");
		printf(">>>>>>>>>>>>>>>>>>>> @ %s @ <<<<<<<<<<<<<<<<<<<<\n", deliverySystem[x][y].context);
		printf("--------------------------------------------------\n");
		printf("--------------------------------------------------\n");
		
		initStorage(x, y);
		storedCnt--;
		
		return 0;
	}
	else {
		printf("----------> Password is Wrong! OTL\n");
		printf("----------> Failed to extract my package!\n");
		
		return -1;
	}

	// 2. after password checking, then put the msg string on the screen and re-initialize the storage
	

	// 3. int x, int y : coordinate of the cell to extract
	

	// 4. return : 0 - successfully extracted, -1 = failed to extract
	
}


//find my package from the storage
//print all the cells (x,y) which has my package
//int nBuilding, int nRoom : my building/room numbers
//return : number of packages that the storage system has
int str_findStorage(int nBuilding, int nRoom) {
	
	// 1. find my package from the storage
	int x, y;							// x = row, y = column of the delivery system
	int cnt = 0;
	
	// 2. print all the cells (x,y) which has my package
	for(x = 0; x < systemSize[0]; x++) {
		for(y = 0; y < systemSize[1]; y++) {

	// 3. int nBuilding, int nRoom : my building/room numbers
			if(strcmp(deliverySystem[x][y].building, nBuilding) == 0 && strcmp(deliverySystem[x][y].room, nRoom) == 0) {

	//4. return : number of packages that the storage system has
				printf(" ---------> Found a package in (%i, %i)\n", x, y);
				cnt++;					// Number of packages found
			}
		}
	}

	return cnt;
}

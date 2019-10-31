#include <stdio.h>
#include <stdlib.h>
#define SIZE 5
#define ROWS 3
#define COLS 3

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

	void printMatrix(int C[][COLS]);

	// Practice 09-4
	
	void square_array(int a[], int size) {
		
		int i;
		for(i = 0; i < size; i++) {
			a[i] = a[i] * a[i];
		}
	}

void print_array(int a[], int size) {
	
	int i;
	for(i = 0; i < size; i++) {
		printf("%d", a[i]);
		printf("\n");
	}
}

int main(int argc, char *argv[]) {
	
	// Practice 09-1
	
	int i1;
	int data[5];
	
	data[0] = 10;
	data[1] = 20;
	data[2] = 30;
	data[3] = 40;
	data[4] = 50;
	
	for(i1 = 0; i1 < 5; i1++)
		printf("data[%i] = %i\n", i1, data[i1]);
	
	printf("\n");
	
	// Practice 09-2
	
	int i2;
	int grade[5];
	int sum, average;
	
	for(i2 = 0; i2 < 5; i2++) {
		
		grade[i2] = rand() % 100;
	}
	printf("\n");
	
	for(i2 = 0; i2 < 5; i2++) {
		printf("grade[%d] = %d\n", i2, grade[i2]);
	}
	printf("\n");
	
	for(i2 = 0; i2 < 5; i2++) {
		printf("put grade %i: ", i2);
		scanf("%d", &grade[i2]);
		sum += grade[i2];
	}
	average = sum / 5;
	printf("The average grades : %d\n", average);
	
	printf("\n");
	
	//	Practice 09-2_Runtime Error
	
	int i3;
	
	printf("A Runtime Error occurs: \n");
	
	grade[0] = 10;
	grade[1] = 10;
	grade[2] = 10;
	grade[3] = 10;
	grade[4] = 10;
	
	grade[5] = 10;
	
	for(i3 = 0; i3 <= 5; i3++) {
		printf("grade[%d] = %d\n", i3, grade[i3]);
	}
	
	printf("\n");
		
	// Practice 09-3-1
	
	int i4;
	int grade2[SIZE];
	int score[SIZE];
	
	for(i4 = 0; i4 < SIZE; i4++) {
		grade2[i4] = rand() % 100;
	}
	
	for(i4 = 0; i4 < SIZE; i4++) {
		score[i4] = grade2[i4];
	}
	
	for(i4 = 0; i4 < SIZE; i4++) {
		printf("score[%d] = %d\n", i4, score[i4]);
	}
	
	printf("\n");
	
	// Practice 09-3-2
	
	int i5;
	int a[5] = {1, 2, 3, 4, 5};
	int b[5] = {1, 2, 2, 4, 5};
	
	for(i5 = 0; i5 < 5; i5++) {
		if(a[i5] != b[i5]) {
			printf("%i is different\n", i5);
		}
	}
	
	printf("\n");
	
	// Practice 09-4
	
	int list[4] = {1, 2, 3, 4};
	
	print_array(list, 4);
	square_array(list, 4);
	print_array(list, 4);
	
	printf("\n");
	
	// Practice 09-6
	
	int A[ROWS][COLS] = {	// Addition Destination Matrix 
		{2, 3, 0},
		{8, 9, 1},
		{7, 0, 5}};

	int B[ROWS][COLS] = {	// Addition Destination Matrix 
		{1, 0, 0},
		{0, 1, 0},
		{0, 0, 1}};
	
	int C[ROWS][COLS];		// Addition Result Matrix 

	addMatrix(A, B, C);
	printMatrix(C);
	
	return 0;
}


void addMatrix(int A[][COLS], int B[][COLS], int C[][COLS]) {
	
	int i, j;
	for(i = 0; i < ROWS; i++) {
		for(j = 0; j < COLS; j++) {
		C[i][j] = A[i][j] + B[i][j];
		}
	}
}

void printMatrix(int C[][COLS]) {
	
	int i, j;
	for(i = 0; i < ROWS; i++) {
		for(j = 0; j < COLS; j++) {
		printf("%i ", C[i][j]);
		}
	printf("\n");
	}
}

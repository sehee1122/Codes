#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
/* 두 개의 정수를 입력받아서 그 사이의 정수를 임의로 선택해서 출력해주는 함수 random() */

int random(int s, int n);

int main(int argc, char *argv[]) {
	
	int y;
	int num1, num2;
	int result;
	int i;
	
	// Create and Initialize variables
	srand((unsigned) time(NULL));	// Set the random seed value
	
	printf("Enter two numbers: ");
	scanf("%d %d", &num1, &num2);
	
	for (i = 0; i < 100; i++)
	{
		result = random(num1, num2);
		printf("%d\t", result);
	}
	
	
	
	return result;
}

int random(int s, int n){
	
	int n_int;
	int boundary;
	
	boundary = abs(n - s) + 1;		// Number of integers between s and n, Include s and n
	
	if(s < n) {
		n_int = rand() % boundary + s;
	}
	
	else if(s > n) {
		n_int = rand() % boundary + n;
	}
	
	else {
		n_int = s;					// Same as s and n		
	}

	return(n_int);
}

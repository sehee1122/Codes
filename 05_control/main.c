#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	
	// Practice 05-1
	
	int input1;
	int input2;
	int input3;
	
	printf("input a number :");
	scanf("%d", &input1);
	
	if (input1 > 0)
		printf("positive\n\n");
	
	else
		printf("non-positive\n\n");
	
	// Practice 05-2
	
	printf("input a number :");
	scanf("%d", &input2);
	
	if (input2 > 0)
		printf("|x| = %d\n\n", input2);
	
	else
		printf("|x| = %d\n\n", -input2);
	
	// Practice 05-3
	
	printf("input a number :");
	scanf("%d", &input3);
	
	if (input3 > 0) {
		printf("positive\n\n");
	}
		
	else if (input3 < 0) {
		printf("negative\n\n");
	}
	
	else
		printf("zero\n\n");
	
	// Practice 05-4
	
	int i;
	int meter; 
	
	while (i < 3) {
		meter = i * 1609;
		printf("%d 마일은 %d 미터입니다.\n", i, meter);
		i++;
	}
	
	printf("\n");
		
	// Practice 05-5
	
	int k;
	for (k = 0; k < 10; k++)
		printf("Hello World!\n");
	
	printf("\n");
	
	// Practice 05-6
	
	int num = 0;
	char c;
	
	printf("input a string: ");

	while ((c = getchar()) != '\n') {
		if ( c >= '0' && c <= '9') {
			num++;
		}
	}
	
	printf("the number of digits is %d\n\n", num);
	
	// Practice 05-7	
	
	int m;
	int n = 1;
	int answer = 59;
	
	printf("Guess a number :");
	scanf("%d", &m);

	do {
		if (m > answer) {
			printf("high!\nGuess a number :");
			scanf("%d", &m);
		}
		
		else {
			printf("low!\nGuess a number :");
			scanf("%d", &m);
		}
		n++;
	} while (m < answer || m > answer);

		printf("Congratulation! trails:%d\n", n);

	return 0;
}

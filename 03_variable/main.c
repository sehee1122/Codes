#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	
	// Practice 03-1
	
	printf("Hello Sookmyung EE!\n\n");

	// Practice 03-2, 03-3
	
	int x;
	char y;
	short z;
	float p;
	double q;
	
	printf("bytes of int : %d\n", sizeof(x));
	printf("bytes of char : %d\n", sizeof(y));
	printf("bytes of short : %d\n", sizeof(z));
	printf("bytes of float : %d\n", sizeof(p));
	printf("bytes of double : %d\n\n", sizeof(q));
	
	// Practice 03-4
	
	int input_int;
	float input_float;
	
	printf("enter an integer : ");
	scanf("%d", &input_int);
	
	printf("enter a float : ");
	scanf("%f", &input_float);
	
	printf("integer : %d, float : %f\n", input_int, input_float);
	
	return 0;
}

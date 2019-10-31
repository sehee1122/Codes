#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

	int square3(int m);

	// Practice 06-1

void print_star() {
	
	int i;

	for(i = 0; i < 10; i++)
		printf("*");
}

	// Practice 06-2, 06-3

int sumTwo(int a, int b) {
	
/*	int output;
	output = a + b;
	return output;	*/
	
	return (a + b);
}

int square(int n) {
	
	return(n * n);
}

int get_max(int x, int y) {
	
	if(x > y)
		return x;
	else
		return y;
}

	// Practice 06-4-1
	
void square2(int n) {
	
	n = n * n;
}

	// Practice 06-7

int factorial (int k) {
	
	int i;
	int res = 1;
	
	for(i = 1; i <= k; i++)
		res *= i;
		
	return res;
}

int calcCombination(int n, int r) {
	
	int mol, den;	// molecule, denominator
	
	mol = factorial(n);
	den = factorial(n-r) * factorial(r);
	
	return (mol/den);
	
}

int main(int argc, char *argv[]) {
	
	// Practice 06-1
	
	print_star();
	print_star();
	print_star();
	
	printf("\n\n");
	
	// Practice 06-2, 06-3
	
	int p;
	int q;
	int output;
	
	p = 2;
	q = 5;
	
	output = sumTwo(p, q);
	printf("sumTwo : %i\n", output);
	
	printf("square : %i\n", square(p));
	
	printf("get_max : %i\n\n", get_max(p, q));
	
	// Practice 06-4-1
	
	square2(p);
	printf("square2 : %i\n\n", p);
	
	// Practice 06-4-2
	
	int result;
	result = square3(5);
	printf("%d\n\n", result);
	
	// Practice 06-6
	
	int i;
	int max = 45;
	
	srand((unsigned) time(NULL));
	
	for (i = 0; i < 6; i++)
		printf("%d\t", 1 + rand() % max);
	
	printf("\n\n");
	
	// Practice 06-7
	
	int n, r;
	int res;
	
	printf("input n and r ");
	scanf("%d %d", &n, &r);
	
	res = calcCombination(n, r);
	printf("combination result is %d\n", res);
	
	return 0;
}

	// Practice 06-4-2

int square3(int m) {
	
	return (m * m);
}

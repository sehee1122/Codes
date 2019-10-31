#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	
	// Practice 04-1
	
	int x1, y, z, m;
	int a, b, c;
	
	x1 = 1;
	z = 3;
	a = 3;
	b = 4;
	c = 5;
	
	y = a*x1*x1 + b*x1 + c;
	m = (x1 + y + z)/3;
	
	printf("y=%d, m=%d\n\n", y, m);
	
	// Practice 04-2
	
	int x2 = 3;
	int cond1, cond2;
	
	cond1 = 2 < x2 && x2 < 5;
	cond2 = x2 > 1 || x2 < 4 && x2 > 3;
	
	printf("cond1=%d,cond2=%d\n\n", cond1, cond2);
	
	// Exercise
	
	printf("-1L < 1U : %d\n", -1L < 1U);
	printf("-1L > 1UL : %d\n\n", -1L > 1UL);
	
	// Practice 04-3
	
	int x0 = 16;
	int y0 = 7;
	int add, sub, mul, div, rem;	// addition, subtraction, multiplication, division, remainder
	
	add = x0 + y0;
	sub = x0 - y0;
	mul = x0 * y0;
	div = x0 / y0;
	rem = x0 % y0;
	
	printf("input two integers : %d %d\n", x0, y0);
	printf("+ result is %d\n", add);
	printf("- result is %d\n", sub);
	printf("* result is %d\n", mul);
	printf("/ result is %d\n", div);
	printf("%% result is %d\n", rem);
	
	return 0;
}

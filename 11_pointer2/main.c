#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

	// Practice 11-4

char *proverb = "All that glisters is not gold.";

void setPointer(char *q) {
	q = proverb;
}

int main(int argc, char *argv[]) {
	
	// Practice 11-1
	
	char *pc1;
	int *pi1;
	double *pd1;
	
	pc1 = (char *)10000;
	pi1 = (int *)10000;
	pd1 = (double *)10000;
	
	printf("Before the Increase : pc = %d, pi = %d, pd = %d\n", pc1, pi1, pd1);
	
	pc1++;
	pi1++;
	pd1++;
	
	printf("After the Increase : pc = %d, pi = %d, pd = %d\n\n", pc1, pi1, pd1);
	
	// Practice 11-2
	
	int i1 = 10;
	int *ptr = &i1;
	
	printf("%i = %d, ptr = %p\n", i1, ptr);
	(*ptr)++;
	printf("%i = %d, ptr = %p\n", i1, ptr);
	*ptr++;
	printf("%i = %d, ptr = %p\n\n", i1, ptr);
	
	// Practice 11-3
	
	char buffer[8];
	double *pd2;
	int *pi2;
	
	pd2 = (double *)buffer;
	*pd2 = 3.14;
	printf("%f\n", *(double *)buffer);
	
	pi2 = (int *)buffer;
	*pi2 = 123;
	*(pi2 + 1) = 456;
	printf("%d %d\n\n", *(int *)buffer, *(int *)buffer + 1);
	
	// Practice 11-4
	
	int i2 = 100;
	int *p1 = &i2;
	int **q1 = &p1;
	
	*p1 = 200;
	printf("i = %d, *p = %d, **q = %d\n", i2, *p1, **q1);
	
	**q1 = 300;
	printf("i = %d, *p = %d, **q = %d\n\n", i2, *p1, **q1);
	
	// Practice 11-5
	
	char *p2 = "zzz";
	setPointer(p2);
	printf("%s\n\n", p2);
	
	
	return 0;
}

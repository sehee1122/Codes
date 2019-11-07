#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

	// Practice 10-4

void swap(int *x, int *y) {
	
	int temp;
	temp = *x;
	*x = *y;
	*y = temp;
}


void main(void) {

	// Practice 10-1
	
	int i1 = 10;
	char c1 = 69;
	float f = 12.3;
	
	printf("i : %i %p \n", &i1, &i1);
	printf("c : %i %p \n", &c1, &c1);
	printf("f : %i %p \n\n", &f, &f);
	
	// Practice 10-2
	
	int i2 = 10;
	char c2 = 'a';
	
	int *iptr;
	char *cptr;
	int *iptr2 = iptr;
	
	iptr = &i2;
	cptr = &c2;
	
	printf("i : %p\n%p (size:%i)\n", iptr, &i2, sizeof(iptr));
	printf("c : %p\n%p (size:%i)\n", cptr, &c2, sizeof(cptr));
	printf("iptr2 : %p, %i\n\n", iptr2, *iptr2);

	// Practice 10-3
	
	int i3 = 4;
	
	int *pi = &i3;
	char *pc = &i3;
	
	printf("%i, %i, %i\n\n", i3, *pi, *pc);	// 4, 4, 4 (when i3 = 4), 300, 300, 44 (when i3 = 300)
	
	// Practice 10-4
	
	int a = 3;
	int b = 5;
	
	swap(&a, &b);
	printf("a: %i, b: %i\n\n", a, b);	// a: 3, b: 5 (when call by value), a: 5, b: 5 (when call by reference)
	
    // Practice 10-5
    
    int i5;
    int grade[5];
    int sum = 0;
    int *gptr;
    
    for(i5 = 0; i5 < 5; i5++) {
    	printf("input value (%i) : ", i5);
    	scanf("%d", &grade[i5]);
	}
	printf("\n");
	
	gptr = grade;
	
	for(i5 = 0; i5 < 5; i5++) {
		printf("grade[%d] = %d\n", i5, *(gptr+i5));
		sum += *(gptr+i5);
	}
	printf("\n -- average : %i\n", sum/5);
}

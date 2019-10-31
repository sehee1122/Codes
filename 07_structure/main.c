#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int inc(int counter);
void f(void);

int k;
int main(int argc, char *argv[]) {
	
	int i = 10;
	printf("before i = %d\n", i);
	inc(i);
	printf("after i = %d\n", i);

	i += 1;
	printf("%d\n\n", i);

	for(k = 0; k < 5; k++) {
		f();
	}

	return 0;
}

int inc(int counter) {
	
	counter++;
	
	return counter;
	
}

void f() {
	for (k = 0; k < 10; k++)
		printf("#");
}

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	
	// Practice 12-2
	
	int i = 0;
	char str[4];
	
	str[0] = 'a';
	str[1] = 'b';
	str[2] = 'c';
	str[3] = '\0';
	
	printf("%s\n", str);
	
	while(str[i] != '\0') {
		printf("%c", str[i]);
		i++;
	}
	
	printf("\n\n");
	
	// Practice 12-3
	
	char src[] = "The worse things to eat before you sleep";
	char dst[100];
	
	strcpy(dst, src);
	
	printf("copied string : %s\n\n", dst);
	
	// Practice 12-4
	
	char str2[30] = "happy C programming";
	
	printf("Length of String \"%s\" is %i\n\n", str2, strlen(str2));
	
	// Practice 12-5
	
	int j;
	char input[100];
	FILE *fp1;
	FILE *fp2;
	
	fp1 = fopen("sample.txt", "w");
	for(j = 0; j < 3; j++) {
		printf("input a word : ");
		scanf("%s", input);
		fprintf(fp1, "%s\n", input);
	}
	fclose(fp1);
	printf("\n");
	
	fp2 = fopen("sample.txt", "r");
	for(j = 0; j < 3; j++) {
		fscanf(fp2, "%s", input);
		printf("%s\n", input);
	}
	fclose(fp2);
	
	return 0;
}

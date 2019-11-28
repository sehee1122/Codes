#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

	// Practice 13-1

/*
struct student {
	int		ID			;
	char	name[10]	;
	double	grade		;
};
*/

	// Practice 13-2
	
int is_whitespace(char c) {
	if (c == ' ' ||
		c == '\n' ||
		c == '\r' ||
		c == '\t' ||
		c == '('	) {
		return 1;
	}
	
	return 0;
}

int fget_word(FILE* fp, char *word) {
	
	int cnt;
	char c;
	
	while ((c = fgetc(fp)) != EOF) {
		if (is_whitespace(c) == 0)
			break;
	}
	
	if ( c == EOF) {
		return 0;
	}
	
	cnt = 0;
	word[cnt++] = c;
	word[cnt] = '\0';
	
	while ((word[cnt] = fgetc(fp)) != EOF) {
		if (is_whitespace(word[cnt]) == 1) {
			word[cnt] = '\0';
			break;
		}
		cnt++;
	}
	return cnt;
}

int main(int argc, char *argv[]) {
	
	// Practice 13-1
/*	
	struct student s1 = { 22, "One's own name'", 4.1};
	s1.ID = 123456;
	strcpy(s1.name, "Juyeop");
	s1.grade = 4.2;
	
	printf("ID : %d\n", s1.ID);
	printf("name : %s\n", s1.name);
	printf("grade : %f\n", s1.grade);
	return 0;
	
	printf("\n");
*/	
	
	// Practice 13-2
	
	FILE *fp;
	char filepath[100];
	char word[100];
	
	// File open
	printf("Input the file path : ");
	scanf("%s", filepath);
	fp = fopen(filepath, "r");
	
	if (fp == NULL) {
		printf("File path is wrong! %s\n", filepath);
		return -1;
	}
	
	// Word reading & analysis
	while (fget_word(fp, word) != 0) {
		printf("%s\n", word);
	}
	
	// Output
	
	fclose(fp);
	return 0;	
}

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

struct student {
	int		ID			;
	char	name[10]	;
	double	grade		;
};

int main(int argc, char *argv[]) {
	
	// Practice 13-1
	
	struct student s1 = { 22, "One's own name'", 4.1};
	s1.ID = 123456;
	strcpy(s1.name, "Juyeop");
	s1.grade = 4.2;
	
	printf("ID : %d\n", s1.ID);
	printf("name : %s\n", s1.name);
	printf("grade : %f\n", s1.grade);
	return 0;
}

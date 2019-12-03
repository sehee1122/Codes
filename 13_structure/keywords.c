#define MAX_NAME	30
#define NKEYS		13

struct keytab {
	int nums;	// 몇번 나오냐
	char name[MAX_NAME]; 
};

struct keytab keywords[NKEYS] = {
	{0, "int"},
	{0, "float"},
	{0, "return"},
	{0, "if"},
	{0, "for"},
	{0, "while"},
	{0, "goto"},
	{0, "switch"},
	{0, "case"},
	{0, "void"},
	{0, "default"},
	{0, "char"},
	{0, "do"}
};

void count_word(char *word) {
	
	int i;
	
	// 각 keyword별로
	for(i = 0; i < 13; i++) {
		// if word랑 i번째 keyword랑 같으면
		if(strncmp(word, keywords[i].name, strlen(keywords[i].name)) == 0) {
			// nums++;
			keywords[i].nums++;
		}
	}
}

void print_word() {
	
	int i;
	
	//  i번째 keyword에 대해서
	for(i = 0; i < 13; i++){
		// printf(키워드 이름 : 빈도수);
		printf("%s : %i\n", keywords[i].name, keywords[i].nums);
	}
}


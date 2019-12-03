#define MAX_NAME	30
#define NKEYS		13

struct keytab {
	int nums;	// ��� ������
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
	
	// �� keyword����
	for(i = 0; i < 13; i++) {
		// if word�� i��° keyword�� ������
		if(strncmp(word, keywords[i].name, strlen(keywords[i].name)) == 0) {
			// nums++;
			keywords[i].nums++;
		}
	}
}

void print_word() {
	
	int i;
	
	//  i��° keyword�� ���ؼ�
	for(i = 0; i < 13; i++){
		// printf(Ű���� �̸� : �󵵼�);
		printf("%s : %i\n", keywords[i].name, keywords[i].nums);
	}
}


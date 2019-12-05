#define MAX_NAME	30
#define N_KEYS		14

struct keytab {
	int nums;	// ��� ������
	char name[MAX_NAME]; 
};

	// Practice 13-4

struct keytab keywords[N_KEYS] = {
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
	{0, "do"},
	{0, "scanf"}
};

void count_word(char *word) {
	
	int i;
	
	// �� keyword����
	for(i = 0; i < N_KEYS; i++) {
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
	for(i = 0; i < N_KEYS; i++){
		// printf(Ű���� �̸� : �󵵼�);
		printf("%s : %i\n", keywords[i].name, keywords[i].nums);
	}
}


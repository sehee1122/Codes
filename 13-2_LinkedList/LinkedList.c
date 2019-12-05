typedef struct linknode {
	
	int data;
	void* next;
} ln_t;

static ln_t *list;	// �ٸ� ���Ͽ��� ������ �Ұ����ϵ��� static

int create_node(int value) {	// node�ϳ� ���� �����ϰ� �����ϴ� ���� 
	
	ln_t *ptr;
	ln_t *ptrTrav;
	int cnt = 0;
	
	ptr = (ln_t*)malloc(sizeof(ln_t));	// ptr = malloc(sizeof(ln_t));
	
	if(ptr == NULL) {		// �޸𸮰� �Ҵ���� �ʾ��� ��� �����Ϳ� �����ϱ� ���� �����Ͽ� ���α׷� �۵��� �������� �ʵ��� ���� 
		// printf
		return -1;
	} 
	
	ptr -> data = value;
	ptr -> next = NULL;		// �������� ����Ű�� ���� �����Ƿ�
	
	if(list == NULL) {		// list�� �����͸� ����Ű����  
		list = ptr;
		cnt = 0;
	}
	
	else {
		ptrTrav =  list;
		cnt++;
		while(ptrTrav -> next != NULL) {	// ���������� ����ų ��� while ���� ������ �Ѵ� 
			ptrTrav = ptrTrav -> next;
			cnt++;
		}
		ptrTrav -> next = ptr;
	}
	
	return cnt;
}

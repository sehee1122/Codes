typedef struct linknode {
	
	int data;
	void* next;
} ln_t;

static ln_t *list;	// 다른 파일에서 접근이 불가능하도록 static

int create_node(int value) {	// node하나 만들어서 선언하고 연결하는 과정 
	
	ln_t *ptr;
	ln_t *ptrTrav;
	int cnt = 0;
	
	ptr = (ln_t*)malloc(sizeof(ln_t));	// ptr = malloc(sizeof(ln_t));
	
	if(ptr == NULL) {		// 메모리가 할당되지 않았을 경우 포인터에 접근하기 전에 선언하여 프로그램 작동이 중지되지 않도록 설정 
		// printf
		return -1;
	} 
	
	ptr -> data = value;
	ptr -> next = NULL;		// 마지막은 가르키는 값이 없으므로
	
	if(list == NULL) {		// list가 포인터를 가르키도록  
		list = ptr;
		cnt = 0;
	}
	
	else {
		ptrTrav =  list;
		cnt++;
		while(ptrTrav -> next != NULL) {	// 마지막까지 가르킬 경우 while 문을 나가게 한다 
			ptrTrav = ptrTrav -> next;
			cnt++;
		}
		ptrTrav -> next = ptr;
	}
	
	return cnt;
}

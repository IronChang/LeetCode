typedef int STDataType;

typedef struct Stack
{
	STDataType* _array;
	size_t _top;
	size_t _capacity;
}Stack;

void StackInit(Stack* ps);//��ʼ��
void StackDestory(Stack* ps);//����
void StackPush(Stack* ps, STDataType x);//β��
void StackPop(Stack* ps);//βɾ
STDataType StackTop(Stack* ps);//ȡ����ǰջ��Ԫ��
int StackEmpty(Stack* ps);//�ж�ջ�Ƿ�Ϊ��
int StackSize(Stack* ps);//�ж�ջ�е�Ԫ�ظ���
void StackPrint(Stack* ps);//��ջ��ȡ��Ԫ��
void PintfStack(Stack* ps);//�鿴ջ��Ԫ��
void Test();


void StackInit(Stack* ps)//��ʼ��
{
	assert(ps);
	ps->_array = NULL;
	ps->_capacity = ps->_top = 0;
}

void StackDestory(Stack* ps)//����
{
	assert(ps);

	free(ps->_array);
	ps->_array = NULL;
	ps->_capacity = ps->_top = 0;
}

void StackPush(Stack* ps, STDataType x)//β��
{
	assert(ps);
    
	if (ps->_top == ps->_capacity)//�ж������Ƿ���
	{
		size_t new_capacity = ps->_array == 0 ? 8 : (ps->_capacity) * 2;//��Ŀ������ж������Ƿ���
		ps->_array = (STDataType*)realloc(ps->_array, new_capacity*sizeof(STDataType));
		assert(ps->_array);//�ж��Ƿ����뵽�ڴ�
		ps->_capacity = new_capacity;
	}
	//��������
	ps->_array[ps->_top] = x;
	ps->_top++;
}

void StackPop(Stack* ps)//βɾ
{
	assert(ps && ps->_array != NULL);

	--ps->_top;//��ջ��ָ����ǰ�ƶ�һλ����ɳ�ջ
}

STDataType StackTop(Stack* ps)//ȡ����ǰջ��Ԫ��
{
	assert(ps && ps->_array != NULL);

	return ps->_array[ps->_top - 1];
}

int StackEmpty(Stack* ps)//�ж�ջ�Ƿ�Ϊ��
{
	assert(ps);
	return ps->_top == 0 ? 0 : 1;
}

int StackSize(Stack* ps)//�ж�ջ�е�Ԫ�ظ���
{
	assert(ps);

	return ps->_top;
}

typedef struct {
    Stack InStack;
    Stack OutStack;
} MyQueue;

/** Initialize your data structure here. */

MyQueue* myQueueCreate() {
    MyQueue* queue = (MyQueue*)malloc(sizeof(MyQueue));
    StackInit(&queue->InStack);
    StackInit(&queue->OutStack);
    
    return queue;
}

/** Push element x to the back of queue. */
void myQueuePush(MyQueue* obj, int x) {
  StackPush(&obj->InStack,x);
}

/** Removes the element from in front of queue and returns that element. */
int myQueuePop(MyQueue* obj) {
  if(StackEmpty(&obj->OutStack) == 0)
  {
      while(StackEmpty(&obj->InStack))
      {
          StackPush(&obj->OutStack,StackTop(&obj->InStack));
          StackPop(&obj->InStack);
      }
  }
    int front = StackTop(&obj->OutStack);
    StackPop(&obj->OutStack);
    
    return front;    
}

/** Get the front element. */
int myQueuePeek(MyQueue* obj) {
    if(StackEmpty(&obj->OutStack) == 0)
  {
      while(StackEmpty(&obj->InStack))
      {
          StackPush(&obj->OutStack,StackTop(&obj->InStack));
          StackPop(&obj->InStack);
      }
  }
    
    return StackTop(&obj->OutStack);
}

/** Returns whether the queue is empty. */
bool myQueueEmpty(MyQueue* obj) {
  return StackEmpty(&obj->InStack) + StackEmpty(&obj->OutStack) == 0 ? true : false;
}

void myQueueFree(MyQueue* obj) {
    StackDestory(&obj->InStack);
    StackDestory(&obj->OutStack);
    
    free(obj);
}

/**
 * Your MyQueue struct will be instantiated and called as such:
 * MyQueue* obj = myQueueCreate();
 * myQueuePush(obj, x);
 
 * int param_2 = myQueuePop(obj);
 
 * int param_3 = myQueuePeek(obj);
 
 * bool param_4 = myQueueEmpty(obj);
 
 * myQueueFree(obj);
*/

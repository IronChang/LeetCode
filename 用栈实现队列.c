typedef int STDataType;

typedef struct Stack
{
	STDataType* _array;
	size_t _top;
	size_t _capacity;
}Stack;

void StackInit(Stack* ps);//初始化
void StackDestory(Stack* ps);//销毁
void StackPush(Stack* ps, STDataType x);//尾插
void StackPop(Stack* ps);//尾删
STDataType StackTop(Stack* ps);//取到当前栈顶元素
int StackEmpty(Stack* ps);//判断栈是否为空
int StackSize(Stack* ps);//判断栈中的元素个数
void StackPrint(Stack* ps);//从栈中取出元素
void PintfStack(Stack* ps);//查看栈中元素
void Test();


void StackInit(Stack* ps)//初始化
{
	assert(ps);
	ps->_array = NULL;
	ps->_capacity = ps->_top = 0;
}

void StackDestory(Stack* ps)//销毁
{
	assert(ps);

	free(ps->_array);
	ps->_array = NULL;
	ps->_capacity = ps->_top = 0;
}

void StackPush(Stack* ps, STDataType x)//尾插
{
	assert(ps);
    
	if (ps->_top == ps->_capacity)//判断容量是否够用
	{
		size_t new_capacity = ps->_array == 0 ? 8 : (ps->_capacity) * 2;//三目运算符判断容量是否够用
		ps->_array = (STDataType*)realloc(ps->_array, new_capacity*sizeof(STDataType));
		assert(ps->_array);//判断是否申请到内存
		ps->_capacity = new_capacity;
	}
	//插入数据
	ps->_array[ps->_top] = x;
	ps->_top++;
}

void StackPop(Stack* ps)//尾删
{
	assert(ps && ps->_array != NULL);

	--ps->_top;//把栈顶指针向前移动一位，完成出栈
}

STDataType StackTop(Stack* ps)//取到当前栈顶元素
{
	assert(ps && ps->_array != NULL);

	return ps->_array[ps->_top - 1];
}

int StackEmpty(Stack* ps)//判断栈是否为空
{
	assert(ps);
	return ps->_top == 0 ? 0 : 1;
}

int StackSize(Stack* ps)//判断栈中的元素个数
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
